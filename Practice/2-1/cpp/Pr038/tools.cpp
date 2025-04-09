// tools.cpp (final)
#include "tools.h"

#include <sstream>
#include <algorithm>

// -----------------------------------------------------------------------------
// 1. Convert every kind of line‑ending to Unix style ("\n")
// -----------------------------------------------------------------------------
void std_newline(std::string &text)
{
    std::string out;
    out.reserve(text.size());

    for (std::size_t i = 0; i < text.size(); ++i)
    {
        char c = text[i];
        if (c == '\r')
        {
            // Windows CRLF => skip CR (leave upcoming LF intact)
            if (i + 1 < text.size() && text[i + 1] == '\n')
                continue;
            // Old‑Mac single CR => convert to LF
            out.push_back('\n');
        }
        else
        {
            out.push_back(c);
        }
    }
    text.swap(out);
}

// -----------------------------------------------------------------------------
// 2. Visualise invisible/control characters.
//    * Characters with ASCII < 32 are shown as their decimal value.
//    * Space (32) and other printable characters stay as‑is so that extra
//      blanks remain visible in the diff.
// -----------------------------------------------------------------------------
static inline bool is_control(unsigned char c) { return c < 32; }

std::string show_chars(const std::string &text)
{
    std::ostringstream oss;
    oss << '[';

    for (std::size_t i = 0; i < text.size(); ++i)
    {
        if (i) oss << ',';
        unsigned char c = static_cast<unsigned char>(text[i]);
        if (is_control(c))
            oss << static_cast<int>(c);
        else
            oss << text[i];
    }
    oss << ']';
    return oss.str();
}

// -----------------------------------------------------------------------------
// 3. Compare two strings and return a minimal diff.
//    * The grading wrapper already prints the raw Program/Expected blocks.
//    * When the two strings are identical (after normalisation) we return an
//      empty string so no extra lines are produced.
//    * On mismatch we return only the "P Output:" / "E Output:" lines that
//      highlight hidden characters, matching the specification example.
// -----------------------------------------------------------------------------
std::string diff_output(const std::string &expected_raw,
                       const std::string &actual_raw)
{
    std::string expected = expected_raw;
    std::string actual   = actual_raw;
    std_newline(expected);
    std_newline(actual);

    if (expected == actual)
        return ""; // no differences – nothing to add.

    std::ostringstream oss;
    oss << "P Output: " << show_chars(actual)   << '\n'
        << "E Output: " << show_chars(expected) << '\n';
    return oss.str();
}
