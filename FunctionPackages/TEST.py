from FunctionPackages.convert_Flash import cStep_Flash
from FunctionPackages.convert_RAM import cStep_RAM
from FunctionPackages.convert_ExternVar import cStep_Extern
from FunctionPackages.convert_Bitmaps import cStep_Bitmaps
from FunctionPackages.parse_Header import *

def test_ALL():

    def test_Flash():
        cStep_Flash('TTale_GTemp_I')

    def test_RAM():
        cStep_RAM()

    def test_Extern():
        cStep_Extern()

    def test_Bitmap():
        cStep_Bitmaps()

    def test_Header():
        print(header_identify())

    """test calls can be enabled/disabled from here."""
    print('TESTING BEGINS')
    # test_Flash()
    # test_RAM()
    # test_Extern()
    # test_Bitmap()
    test_Header()
    print('TESTING FINISHED')
