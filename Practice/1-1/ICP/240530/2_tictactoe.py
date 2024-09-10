import tkinter as tk

def calculate():
    try:
        result = eval(entry.get())
        result_label.config(text=f"결과: {result}")
    except Exception as e:
        result_label.config(text="에러: 잘못된 수식")

# 메인 윈도우 생성
window = tk.Tk()
window.title("간단한 계산기")

# 수식 입력을 위한 Entry 위젯 생성
entry = tk.Entry(window, width=20)
entry.pack(pady=10)

# 계산 버튼 생성
calc_button = tk.Button(window, text="계산", command=calculate)
calc_button.pack(pady=5)

# 결과를 표시할 Label 위젯 생성
result_label = tk.Label(window, text="결과:")
result_label.pack(pady=5)

# 메인 루프 실행
window.mainloop()