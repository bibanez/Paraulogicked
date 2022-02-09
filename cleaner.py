import re           # Work with regular expressions
import unidecode    # You may need to install this package with pip

# Replace with your dictionary file
f = open("ca.dic", "r")
lines = f.readlines()
f.close()
print(len(lines))
                                                                                                                              cleaned = []
for i in range(len(lines)):
    line = lines[i]    
    # Match any one or more characters different from '/' at the start    
    # of the string    
    x = re.search("^[^\\\/\d]+", line)
    
    if (x != None):
        x = x.group().lower()
        
        # Simplify special characters such as 'á' or 'ç' into 'a' and 'c'
        x = unidecode.unidecode(x)                                                   
        
        # Correct 'l*l' into 'll' and delete ', - and \
        x = re.sub("\*|'|-", "", x)
        
        cleaned.append(x)
    print(i)

print("Finished!")

# Remove duplicates
cleaned = list(dict.fromkeys(cleaned))

# This step sorts the wordlist in alphabetical order
cleaned.sort()

# Save file
with open("ca_netejat.txt", "w") as txt_file:
    for line in cleaned: txt_file.write(line + "\n")
