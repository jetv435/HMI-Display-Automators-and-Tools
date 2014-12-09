import os

def header_identify():
    """identifies key features and points within the .h header file to assist in modification"""

    def header_read():
        """returns the contents of the .h header file as a list of lines from the file"""
        os.chdir('header_IN')
        filename = 'lcd_grph.h'
        lcd_grph = open(filename, 'r')
        headerLines = lcd_grph.readlines()
        lcd_grph.close()
        os.chdir('..')

        return headerLines

    def header_lExtern(source):
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

    def header_lRAM(source):
        """finds the last RAM_ADDR definition line"""
        headerLines = source

        ramLines = []

        for i in range(len(headerLines)):
            if (headerLines[i][0] != '/') and ('#define RAM_ADDR_' in headerLines[i]):
                ramLines.append(i)

        return ramLines[-1]

    def header_ALL():
        """initiates the processes of the main identification function"""
        return [header_lExtern(header_read()), header_lFlash(header_read()), header_lRAM(header_read())]

    return header_ALL()

def header_edit(data):
    """creates a copy of the .h header file with the necessary chances made"""
    return 0