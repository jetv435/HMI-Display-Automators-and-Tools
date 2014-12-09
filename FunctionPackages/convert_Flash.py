import os

def cStep_Flash(previous):

    def flash_Line(input, pre_input, pre_size_name): # input is a given filename
                                                    # pre_input is the name of the previous bitmap before insertion
                                                    # pre_size_name is the name of the previous bitmap without extention

        noBMP = input.replace('.c', '')
        withCAPS = noBMP.upper()
        withFLASH = 'FLASH_ADDR_{}'.format(withCAPS)

        pre_noBMP = pre_input.replace('.c', '')
        pre_withCAPS = pre_noBMP.upper()
        pre_withFLASH = 'FLASH_ADDR_{}'.format(pre_withCAPS)

        numSpaces = 48 - len(withFLASH)

        pasteLine = '#define {}{}{}+sizeof({})'.format(withFLASH, ' ' * numSpaces, pre_withFLASH, pre_size_name)

        return pasteLine

    def flash_Batch(input, previous): # input is the list of bitmap file names,
                                        # previous is the name of the bitmap before the new bitmaps are inserted

        pasteList = []
        currentPrevious = previous

        for k in input:
            pasteList.append(flash_Line(k, currentPrevious, currentPrevious.replace('.c', '')) + '\n')
            currentPrevious = k.replace('.c', '')

        return pasteList

    def flash_Write(input, previous): # input is the list of bitmap file names,
                                        # previous is the name of the bitmap before the new bitmaps are inserted

        pasteList = flash_Batch(input, previous)

        os.chdir('output')

        filename = 'flashTXT.h'
        pasteFile = open(filename, 'w')

        for i in pasteList:
            pasteFile.writelines(i)

        pasteFile.close()
        os.chdir('..')

        return pasteList

    def flash_Read():
        os.chdir('bitmaps_In')
        bitmapList = os.listdir()
        os.chdir('..')
        return bitmapList

    def flash_ALL(previous): # previous is the name of the bitmap before the new bitmaps are inserted
        bitmapList = flash_Read()
        return flash_Write(bitmapList, previous)

    return flash_ALL(previous)