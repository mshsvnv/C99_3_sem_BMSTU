import os
import shutil

cur_dir = "./data/"
out_dir = "./data_preproc/"
data = os.listdir(path = cur_dir)

if not os.path.exists(out_dir):
    os.mkdir(out_dir)
else:
    shutil.rmtree(out_dir)
    os.mkdir(out_dir)

for file in data:
    with open(cur_dir + file) as f:

        file = file[:-4]
        array = list(map(int, [row.strip() for row in f]))
        
        aver = sum(array) / len(array)

        name_aver = out_dir + file + "_aver.txt"
        with open(name_aver, "w") as f_aver:
            f_aver.write(str(aver))

