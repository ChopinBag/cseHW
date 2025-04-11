import whisper
url = "/Users/imseung-u/Downloads/0313.m4a"
model = whisper.load_model("base")
result = model.transcribe(url)  # 너의 파일 경로로 변경
print(result["text"])