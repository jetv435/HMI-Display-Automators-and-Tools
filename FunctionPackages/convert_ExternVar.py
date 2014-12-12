import os

def cStep_Extern():

    def extern_Line(index, input): # input is a list of bitmap file names,
                                    #  index is the location of the current file in the list

        uneditedSTR = extern_bitmapInfo(index, input).replace('\n', '')
        resList = extern_bitmapSize(index, input)

        editedSTR = uneditedSTR.replace(' = { ', ';')

        resLine = '// BITMAP SIZE: X={} Y={} Total={}\n'.format(resList[0], resList[1], resList[0] * resList[1])

        numSpaces = 53 - len(editedSTR)

        pasteLine = 'extern {}{}{}'.format(editedSTR, ' ' * numSpaces, resLine)
        return pasteLine

    def extern_bitmapInfo(index, input): # input is a list of bitmap file names,
                                    #  index is the location of the current file in the list

        os.chdir('bitmaps_IN')

        filename = input[index]
        bitmapfile = open(filename, 'r')

        try:
            bitmaplines = bitmapfile.readlines()
        except:
            print(bitmapfile)
            return 'ERROR'

        bitmapfile.close()
        os.chdir('..')

        externline = bitmaplines[7]

        return externline

    def extern_bitmapSize(index, input): # input is a list of bitmap file names,
                                    #  index is the location of the current file in the list

        os.chdir('bitmaps_IN')

        filename = input[index]
        bitmapfile = open(filename, 'r')
        bitmaplines = bitmapfile.readlines()
        bitmapfile.close()
        os.chdir('..')

        resLine = bitmaplines[3]

        resX = ''
        resY = ''

        i = 0
        while resLine[i] != 'X':
            i += 1

        i += 2
        while resLine[i] != ' ':
            resX = resX + resLine[i]
            i += 1

        i += 3
        while resLine[i] != ' ':
            resY = resY + resLine[i]
            i += 1

        resList = [int(resX), int(resY)]

        return resList

    def extern_Batch(input): # input is a list of bitmap file names
        pasteList = []

        for k in range(len(input)):
            pasteList.append(extern_Line(k, input))

        return pasteList

    def extern_Read():
        os.chdir('bitmaps_IN')
        bitmapList = os.listdir()
        os.chdir('..')
        return bitmapList

    def extern_Write(input): # input is a list of bitmap file names
        pasteList = extern_Batch(input)

        os.chdir('output')

        filename = 'externTXT.h'
        pasteFile = open(filename, 'w')

        for i in pasteList:
            pasteFile.writelines(i)

        pasteFile.close()
        os.chdir('..')

        return pasteList

    def extern_ALL():
        bitmapList = extern_Read()
        return extern_Write(bitmapList)

    return extern_ALL()