import os 
import time

row = int(input("What row will we be doing today?\n"))
col = 0
filename = os.path.dirname(os.path.realpath(__file__)) + "\\code.c"
outfile = open(filename,'w')
while col < 16:
    info = raw_input("What instruction is 0x" + hex((row<<4)+col) + "?\n")
    outfile.write("\tcase " + str(hex((row<<4)+col)) + ":\n")
    outfile.write("\t\t//" + info + "\n")
    outfile.write("\t\t\n")
    #outfile.write("\t\tpc++;\n")
    outfile.write("\t\treturn 0;\n")
    outfile.write("\n")
    col += 1

print "Created File: " + filename + ". Closing in 10 seconds"
time.sleep(10)