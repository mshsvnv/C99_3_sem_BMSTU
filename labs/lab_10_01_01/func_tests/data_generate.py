import random as r

Codes = {"Alanine": ["GSU", "GSS"],
         "Valine": ["GUU", "GYS"],
         "Glycine": ["GGU", "GGS"],
         "Lizine": ["AAA", "AAG"]}

file = open("./data/file_in.txt", "w")

for i in range(10):
    amino_acid = r.choice(list(Codes.keys())) 
    triplet = r.choice(Codes[amino_acid])
    amounts = r.randint(1, 10)

    string = amino_acid + "\n" + triplet + "\n" + str(amounts) + "\n"
    
    file.write(string)

file.close()