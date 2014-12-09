import os

def cStep_Bitmaps():

    def bitmaps_Read():
        os.chdir('bitmaps_In')
        bitmapList = os.listdir()
        os.chdir('..')
        return bitmapList

    def bitmaps_line(input, fname): # input is a line in the file
        strSize = ''

        bitname = fname.replace('.c', '')

        i = 22 + len(bitname)

        while input[i] != ']':
            strSize = strSize + input[i]
            i += 1

        size = int(strSize)

        baseName = bitname.replace('.c', '')
        baseCaps = baseName.upper()
        flash = 'FLASH_ADDR_{}'.format(baseCaps)

        newLine = 'const unsigned short {}[/*{}*/] __at__({}) = {{ \n'.format(bitname, size, flash)

        return newLine

    def bitmaps_convert(input): # input is a single filename
        newlines = ['#include <absacc.h>\n', '#include "lcd_grph.h"\n\n']

        os.chdir('bitmaps_IN')
        filename = input
        bitmapfile = open(filename, 'r')
        bitlines = bitmapfile.readlines()
        bitmapfile.close()
        os.chdir('..')

        for i in range(len(bitlines)):
            if i == 7:
                newlines.append(bitmaps_line(bitlines[i], input))
            else:
                newlines.append(bitlines[i])

        return newlines

    def bitmaps_WriteBatch(input ): # input is the list of files
        for i in input:
            newlines = bitmaps_convert(i)

            os.chdir(os.path.join('output', 'Bitmaps_OUT'))
            filename = i
            bitmapfile = open(filename, 'w')

            for k in newlines:
                bitmapfile.writelines(k)

            bitmapfile.close()
            os.chdir('..')
            os.chdir('..')

    def bitmaps_ALL():
        bitmapList = bitmaps_Read()
        bitmaps_WriteBatch(bitmapList)

    bitmaps_ALL()
    return 'Bitmap edit conversion complete'
