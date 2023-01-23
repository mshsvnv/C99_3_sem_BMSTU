import os
import shutil

file_x = "keys.txt"

dir_source = "./data_preproc/"
dir_out = "./data_postproc/"

if not os.path.exists(dir_out):
    os.mkdir(dir_out)
else:
    shutil.rmtree(dir_out)
    os.mkdir(dir_out)

prog = []
sizes = []
with open(file_x) as f:
    k = 1
    for i in f:
        if  k == 2:
            prog.append([x for x in i.split()]) 
        elif k == 1:
            sizes.append([x for x in i.split()])
        else:
            optim = [x for x in i.split()] 
        k += 1
        
for i in range(len(prog)):
    for opt in optim:
        for j in range(len(prog[i])):

            make_file = dir_out + prog[i][j] + '_' + opt + "_grap_{}.txt".format(i + 1)

            for k in range(len(prog[i])):
                    
                with open(make_file, "w") as f:

                    for x in sizes[i]:

                        string = x + ' '

                        source_file = dir_source + prog[i][j] + '_' + opt + '_' + x + "_aver.txt"
                        
                        with open(source_file) as f_s:
                            string += f_s.readline().strip() + '\n'

                        f.write(string)
