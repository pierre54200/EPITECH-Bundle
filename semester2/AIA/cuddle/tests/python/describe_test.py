import pandas as pd
from tkinter import filedialog

file_path = filedialog.askopenfilename(title="Select a file")
df = pd.read_csv(file_path)


print("\nSummary Statistics:")
print(df.describe())
