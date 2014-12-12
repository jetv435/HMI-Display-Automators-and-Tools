import os

def cStep_RAM():

    def ram_Line(input): # input is an individual filename

        noBMP = input.replace('.c', '')
        withCAPS = noBMP.upper()
        withRAM = 'RAM_ADDR_{}'.format(withCAPS)

        withnoBMPf = input.replace('.c', '')
        withCAPSf = withnoBMPf.upper()
        withFLASHf = 'FLASH_ADDR_{}'.format(withCAPSf)

        numSpaces = 48 - len(withRAM)

        pasteLine = '#define {}{}{} + OFFSET_NOR_RAM'.format(withRAM, ' ' * numSpaces, withFLASHf)

        return pasteLine

    def ram_Batch(input): # input is a list of bitmap filenames
        pasteList = []

        for k in input:
            pasteList.append(ram_Line(k) + '\n')

        return pasteList

    def ram_Write(input): # input is a list of bitmap filenames
        pasteList = ram_Batch(input)

        os.chdir('output')

        filename = 'ramTXT.h'
        pasteFile = open(filename, 'w')

        for i in pasteList:
            pasteFile.writelines(i)

        pasteFile.close()
        os.chdir('..')

        return pasteList

    def ram_Read():
        os.chdir('bitmaps_IN')
        bitmapList = os.listdir()
        os.chdir('..')
        return bitmapList

    def ram_ALL():
        bitmapList = ram_Read()
        return ram_Write(bitmapList)

    return ram_ALL()
