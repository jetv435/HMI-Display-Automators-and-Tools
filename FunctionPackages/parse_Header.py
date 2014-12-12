import os

def header_identify():
    """identifies key features and points within the .h header file to assist in modification"""

    def hident_read():
        """returns the contents of the .h header file as a list of lines from the file"""
        os.chdir('header_IN')
        filename = 'lcd_grph.h'
        lcd_grph = open(filename, 'r')
        headerLines = lcd_grph.readlines()
        lcd_grph.close()
        os.chdir('..')

        return headerLines

    def hident_lExtern(source):
        """finds the last Extern definition line"""
        headerLines = source

        externLines = []

        for i in range(len(headerLines)):
            if (headerLines[i][0] != '/') and ('extern const unsigned short') in headerLines[i]:
                externLines.append(i)

        return externLines[-1]

    def header_lFlash(source):
        """finds the last FLASH_ADDR definition line"""
        headerLines = source

        flashLines = []

        for i in range(len(headerLines)):
            if (headerLines[i][0] != '/') and ('#define FLASH_ADDR_' in headerLines[i]):
                flashLines.append(i)

        return [flashLines[-2], flashLines[-1]]

    def hident_lRAM(source):
        """finds the last RAM_ADDR definition line"""
        headerLines = source

        ramLines = []

        for i in range(len(headerLines)):
            if (headerLines[i][0] != '/') and ('#define RAM_ADDR_' in headerLines[i]):
                ramLines.append(i)

        return ramLines[-1]

    def hident_ALL():
        """initiates the processes of the main identification function"""
        return [hident_lExtern(hident_read()), header_lFlash(hident_read()), hident_lRAM(hident_read())]

    return hident_ALL()

def header_edit(pData, externInfo, flashInfo, ramInfo):
    """creates a copy of the .h header file with the necessary chances made"""

    def hedit_read():
        """returns the contents of the .h header file as a list of lines from the file"""
        os.chdir('header_IN')
        filename = 'lcd_grph.h'
        lcd_grph = open(filename, 'r')
        headerLines = lcd_grph.readlines()
        lcd_grph.close()
        os.chdir('..')

        return headerLines

    def hedit_write(headerLines):

        os.chdir('output')
        filename = 'lcd_grph.h'
        lcd_grph = open(filename, 'w')

        for i in range(len(headerLines)):
            if i == pData[0] + 1:
                lcd_grph.writelines('\n')
                for k in externInfo:
                    lcd_grph.writelines(k)
            elif i == pData[1][0] + 1:
                lcd_grph.writelines('\n')
                for k in flashInfo:
                    lcd_grph.writelines(k)
            elif i == pData[2] + 1:
                lcd_grph.writelines('\n')
                for k in ramInfo:
                    lcd_grph.writelines(k)
            elif i == pData[1][1]:
                lcd_grph.writelines(hedit_flashend())
                continue

            lcd_grph.writelines(headerLines[i])

        lcd_grph.close()
        os.chdir('..')

    def hedit_flashend():
        endcaps = '*REPLACE_ME*'
        endlower = '*replace_me*'

        return '#define FLASH_ADDR_SIZE                               ((FLASH_ADDR_{}+sizeof({})+2)-FLASH_EXTERN_START_ADDR)\n'.format(endcaps, endlower)

    def hedit_ALL():
        headerLines = hedit_read()
        hedit_write(headerLines)

    hedit_ALL()