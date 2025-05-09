import pandas as pd
from tkinter import filedialog

file_path = filedialog.askopenfilename(title="Select a file")
df = pd.read_csv(file_path)

print("Head 1000:")
print(df.head(1000))

print("Head 1:")
print(df.head(1))

print("Head 0:")
print(df.head(0))

print("Head -1:")
print(df.head(-1))

print("Head -6:")
print(df.head(-6))
