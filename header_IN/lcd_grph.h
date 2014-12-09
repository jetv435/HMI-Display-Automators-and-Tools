#ifndef _LCD_GRPH_
#define _LCD_GRPH_

/*********************************************************************************************
	1.	INCLUDE FILES
*********************************************************************************************/
#include "lpc_types.h"
#include "lcd_seed_fill.h" //include if seed fill is to be used

#define DISPLAY_WIDTH  800
#define DISPLAY_HEIGHT 480

#define WIDTH_KEY	110
#define HEIGHT_KEY	60

#define WIDTH_SLIDER_COLORI		60
#define HEIGHT_SLIDER_COLORI	215

/*********************************************************************************************
	2.	Extern Variables
*********************************************************************************************/

extern const unsigned short ACP_Logo[9360];
extern const unsigned short Battery_gauge[5940];
extern const unsigned short Error_Indicator[1710];
extern const unsigned short splash_screen[560*68];
//extern const unsigned char font_mentone_42[91][252];

extern const unsigned char Mentone_13[2692];
extern const unsigned char Mentone_68[8666];
extern const unsigned char Mentone_31[11294];
extern const unsigned char Mentone_21[6410];
extern const unsigned char Mentone_31_Mono[2228];
extern const unsigned char Mentone_21_Mono[1484];

extern const unsigned short FGauge_FIcon[625];
extern const unsigned short FGauge_Full[6527];
extern const unsigned short HPEV_Logo_Footer[8372];
extern const unsigned short HPEV_Logo_Splash[102400];
extern const unsigned short NavB_Eng_A[704];
extern const unsigned short NavB_Eng_I[704];
extern const unsigned short NavB_Gen_A[588];
extern const unsigned short NavB_Gen_I[588];
extern const unsigned short NavB_Opt_A[702];
extern const unsigned short NavB_Opt_I[702];
extern const unsigned short TGauge_Bulb_Green[750];
extern const unsigned short TGauge_Bulb_Red[750];
extern const unsigned short TGauge_Bulb_Yellow[750];
extern const unsigned short TGauge_GIcon[784];
extern const unsigned short TGauge_Tube[2548];
extern const unsigned short TTale_ETemp_A[2304];
extern const unsigned short TTale_ETemp_I[2304];
extern const unsigned short TTale_FuelL_A[2304];
extern const unsigned short TTale_FuelL_I[2304];
extern const unsigned short TTale_GStat_A_Err[2304];
extern const unsigned short TTale_GStat_A_On[2304];
extern const unsigned short TTale_GStat_I[2304];
extern const unsigned short TTale_GTemp_A[2304];
extern const unsigned short TTale_GTemp_I[2304];
extern const unsigned short TTale_PBrak_A[2304];
extern const unsigned short TTale_PBrak_I[2304];
extern const unsigned short TTale_PTemp_A[2304];
extern const unsigned short TTale_PTemp_I[2304];
extern const unsigned short TTale_TTemp_A[2304];
extern const unsigned short TTale_TTemp_I[2304];
extern const unsigned short TTale_Warn_A[2304];
extern const unsigned short TTale_Warn_I[2304];

/****************************************************/
/* Bitmap allocation table, ext flash memory		*/
/****************************************************/
#define FLASH_EXTERN_START_ADDR						0x80000000	/* External Flash memory base address */
#define FLASH_ADDR_BATT_GAUGE							FLASH_EXTERN_START_ADDR
#define FLASH_ADDR_ERROR_INDICATOR				FLASH_ADDR_BATT_GAUGE + sizeof(Battery_gauge)

#define FLASH_ADDR_ACP_LOGO								FLASH_ADDR_ERROR_INDICATOR+sizeof(Error_Indicator)
#define FLASH_ADDR_SPLASH_SCREEN					FLASH_ADDR_ACP_LOGO+sizeof(ACP_Logo)

#define FLASH_ADDR_FONT_MENTONE_13				FLASH_ADDR_SPLASH_SCREEN+sizeof(splash_screen)
#define FLASH_ADDR_FONT_MENTONE_68				FLASH_ADDR_FONT_MENTONE_13+sizeof(Mentone_13)
#define FLASH_ADDR_FONT_MENTONE_31				FLASH_ADDR_FONT_MENTONE_68+sizeof(Mentone_68)+2
#define FLASH_ADDR_FONT_MENTONE_21				FLASH_ADDR_FONT_MENTONE_31+sizeof(Mentone_31)+2
#define FLASH_ADDR_FONT_MENTONE_31_MONO		FLASH_ADDR_FONT_MENTONE_21+sizeof(Mentone_21)+2
#define FLASH_ADDR_FONT_MENTONE_21_MONO		FLASH_ADDR_FONT_MENTONE_31_MONO+sizeof(Mentone_31_Mono)

#define	FLASH_ADDR_FGAUGE_FICON						FLASH_ADDR_FONT_MENTONE_21_MONO+sizeof(Mentone_21_Mono)
#define FLASH_ADDR_FGAUGE_FULL						FLASH_ADDR_FGAUGE_FICON+sizeof(FGauge_FIcon)+2
#define FLASH_ADDR_HPEV_LOGO_FOOTER				FLASH_ADDR_FGAUGE_FULL+sizeof(FGauge_Full)+2
#define FLASH_ADDR_HPEV_LOGO_SPLASH				FLASH_ADDR_HPEV_LOGO_FOOTER+sizeof(HPEV_Logo_Footer)
#define FLASH_ADDR_NAVB_ENG_A                           FLASH_ADDR_HPEV_LOGO_SPLASH+sizeof(HPEV_Logo_Splash)
#define FLASH_ADDR_NAVB_ENG_I							FLASH_ADDR_NAVB_ENG_A+sizeof(NavB_Eng_A)
#define FLASH_ADDR_NAVB_GEN_A							FLASH_ADDR_NAVB_ENG_I+sizeof(NavB_Eng_I)
#define FLASH_ADDR_NAVB_GEN_I							FLASH_ADDR_NAVB_GEN_A+sizeof(NavB_Gen_A)
#define FLASH_ADDR_NAVB_OPT_A							FLASH_ADDR_NAVB_GEN_I+sizeof(NavB_Gen_I)
#define FLASH_ADDR_NAVB_OPT_I							FLASH_ADDR_NAVB_OPT_A+sizeof(NavB_Opt_A)
#define FLASH_ADDR_TGAUGE_BULB_GREEN			FLASH_ADDR_NAVB_OPT_I+sizeof(NavB_Opt_I)
#define FLASH_ADDR_TGAUGE_BULB_RED				FLASH_ADDR_TGAUGE_BULB_GREEN+sizeof(TGauge_Bulb_Green)
#define FLASH_ADDR_TGAUGE_BULB_YELLOW			FLASH_ADDR_TGAUGE_BULB_RED+sizeof(TGauge_Bulb_Red)
#define FLASH_ADDR_TGAUGE_GICON						FLASH_ADDR_TGAUGE_BULB_YELLOW+sizeof(TGauge_Bulb_Yellow)
#define FLASH_ADDR_TGAUGE_TUBE						FLASH_ADDR_TGAUGE_GICON+sizeof(TGauge_GIcon)
#define FLASH_ADDR_TTALE_ETEMP_A					FLASH_ADDR_TGAUGE_TUBE+sizeof(TGauge_Tube)
#define	FLASH_ADDR_TTALE_ETEMP_I					FLASH_ADDR_TTALE_ETEMP_A+sizeof(TTale_ETemp_A)
#define FLASH_ADDR_TTALE_FUELL_A					FLASH_ADDR_TTALE_ETEMP_I+sizeof(TTale_ETemp_I)
#define FLASH_ADDR_TTALE_FUELL_I					FLASH_ADDR_TTALE_FUELL_A+sizeof(TTale_FuelL_A)
#define FLASH_ADDR_TTALE_GSTAT_A_ERR			FLASH_ADDR_TTALE_FUELL_I+sizeof(TTale_FuelL_A)
#define FLASH_ADDR_TTALE_GSTAT_A_ON				FLASH_ADDR_TTALE_GSTAT_A_ERR+sizeof(TTale_GStat_A_Err)
#define FLASH_ADDR_TTALE_GSTAT_I					FLASH_ADDR_TTALE_GSTAT_A_ON+sizeof(TTale_GStat_A_On)
#define FLASH_ADDR_TTALE_PBRAK_A					FLASH_ADDR_TTALE_GSTAT_I+sizeof(TTale_GStat_I)
#define FLASH_ADDR_TTALE_PBRAK_I					FLASH_ADDR_TTALE_PBRAK_A+sizeof(TTale_PBrak_A)
#define FLASH_ADDR_TTALE_PTEMP_A					FLASH_ADDR_TTALE_PBRAK_I+sizeof(TTale_PBrak_I)
#define FLASH_ADDR_TTALE_PTEMP_I					FLASH_ADDR_TTALE_PTEMP_A+sizeof(TTale_PTemp_A)
#define FLASH_ADDR_TTALE_TTEMP_A					FLASH_ADDR_TTALE_PTEMP_I+sizeof(TTale_PTemp_I)
#define FLASH_ADDR_TTALE_TTEMP_I					FLASH_ADDR_TTALE_TTEMP_A+sizeof(TTale_TTemp_A)
#define FLASH_ADDR_TTALE_WARN_A						FLASH_ADDR_TTALE_TTEMP_I+sizeof(TTale_TTemp_I)
#define FLASH_ADDR_TTALE_WARN_I						FLASH_ADDR_TTALE_WARN_A+sizeof(TTale_Warn_A)
#define FLASH_ADDR_TTALE_GTEMP_A					FLASH_ADDR_TTALE_WARN_I+sizeof(TTale_Warn_I)
#define FLASH_ADDR_TTALE_GTEMP_I					FLASH_ADDR_TTALE_GTEMP_A+sizeof(TTale_GTemp_A)

//Can be used for copying flash memory to external ram
#define FLASH_ADDR_SIZE									((FLASH_ADDR_TTALE_GTEMP_I+sizeof(TTale_GTemp_I)+2)-FLASH_EXTERN_START_ADDR)

#define FLASH_IMAGE_IN_RAM_START_ADDR		0xA02EE000	/* Start copy Ext Flash to Ext RAM */
#define OFFSET_NOR_RAM						0x202EE000

/****************************************************/
/* Bitmap allocation table, ext RAM memory		    */
/****************************************************/

#define RAM_ADDR_ACP_LOGO									FLASH_ADDR_ACP_LOGO + OFFSET_NOR_RAM				
#define RAM_ADDR_SPLASH_SCREEN	        	FLASH_ADDR_SPLASH_SCREEN + OFFSET_NOR_RAM			
#define RAM_ADDR_BATT_GAUGE								FLASH_ADDR_BATT_GAUGE + OFFSET_NOR_RAM
#define RAM_ADDR_ERROR_INDICATOR					FLASH_ADDR_ERROR_INDICATOR + OFFSET_NOR_RAM

#define RAM_ADDR_FONT_MENTONE_13					FLASH_ADDR_FONT_MENTONE_13 + OFFSET_NOR_RAM	
#define RAM_ADDR_FONT_MENTONE_68					FLASH_ADDR_FONT_MENTONE_68 + OFFSET_NOR_RAM
#define RAM_ADDR_FONT_MENTONE_31					FLASH_ADDR_FONT_MENTONE_31 + OFFSET_NOR_RAM
#define RAM_ADDR_FONT_MENTONE_21					FLASH_ADDR_FONT_MENTONE_21 + OFFSET_NOR_RAM
#define RAM_ADDR_FONT_MENTONE_31_MONO			FLASH_ADDR_FONT_MENTONE_31_MONO + OFFSET_NOR_RAM
#define RAM_ADDR_FONT_MENTONE_21_MONO			FLASH_ADDR_FONT_MENTONE_21_MONO + OFFSET_NOR_RAM

#define RAM_ADDR_FGAUGE_FICON							FLASH_ADDR_FGAUGE_FICON + OFFSET_NOR_RAM
#define RAM_ADDR_FGAUGE_FULL							FLASH_ADDR_FGAUGE_FULL + OFFSET_NOR_RAM
#define RAM_ADDR_HPEV_LOGO_FOOTER					FLASH_ADDR_HPEV_LOGO_FOOTER + OFFSET_NOR_RAM
#define RAM_ADDR_HPEV_LOGO_SPLASH					FLASH_ADDR_HPEV_LOGO_SPLASH + OFFSET_NOR_RAM
#define RAM_ADDR_NAVB_ENG_A								FLASH_ADDR_NAVB_ENG_A + OFFSET_NOR_RAM
#define RAM_ADDR_NAVB_ENG_I								FLASH_ADDR_NAVB_ENG_I	+ OFFSET_NOR_RAM
#define RAM_ADDR_NAVB_GEN_A								FLASH_ADDR_NAVB_GEN_A + OFFSET_NOR_RAM
#define RAM_ADDR_NAVB_GEN_I								FLASH_ADDR_NAVB_GEN_I + OFFSET_NOR_RAM
#define RAM_ADDR_NAVB_OPT_A								FLASH_ADDR_NAVB_OPT_A + OFFSET_NOR_RAM
#define RAM_ADDR_NAVB_OPT_I								FLASH_ADDR_NAVB_OPT_I + OFFSET_NOR_RAM
#define RAM_ADDR_TGAUGE_BULB_GREEN				FLASH_ADDR_TGAUGE_BULB_GREEN + OFFSET_NOR_RAM
#define RAM_ADDR_TGAUGE_BULB_RED					FLASH_ADDR_TGAUGE_BULB_RED + OFFSET_NOR_RAM
#define RAM_ADDR_TGAUGE_BULB_YELLOW				FLASH_ADDR_TGAUGE_BULB_YELLOW + OFFSET_NOR_RAM
#define RAM_ADDR_TGAUGE_GICON							FLASH_ADDR_TGAUGE_GICON + OFFSET_NOR_RAM
#define RAM_ADDR_TGAUGE_TUBE							FLASH_ADDR_TGAUGE_TUBE + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_ETEMP_A						FLASH_ADDR_TTALE_ETEMP_A + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_ETEMP_I						FLASH_ADDR_TTALE_ETEMP_I + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_FUELL_A						FLASH_ADDR_TTALE_FUELL_A + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_FUELL_I						FLASH_ADDR_TTALE_FUELL_I + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_GSTAT_A_ERR				FLASH_ADDR_TTALE_GSTAT_A_ERR + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_GSTAT_A_ON					FLASH_ADDR_TTALE_GSTAT_A_ON + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_GSTAT_I						FLASH_ADDR_TTALE_GSTAT_I + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_GTEMP_A						FLASH_ADDR_TTALE_GTEMP_A + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_GTEMP_I						FLASH_ADDR_TTALE_GTEMP_I + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_PBRAK_A						FLASH_ADDR_TTALE_PBRAK_A + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_PBRAK_I						FLASH_ADDR_TTALE_PBRAK_I + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_PTEMP_A						FLASH_ADDR_TTALE_PTEMP_A + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_PTEMP_I						FLASH_ADDR_TTALE_PTEMP_I + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_TTEMP_A						FLASH_ADDR_TTALE_TTEMP_A + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_TTEMP_I						FLASH_ADDR_TTALE_TTEMP_I + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_WARN_A							FLASH_ADDR_TTALE_WARN_A + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_WARN_I							FLASH_ADDR_TTALE_WARN_I + OFFSET_NOR_RAM
#define RAM_ADDR_TTALE_GTEMP_A						FLASH_ADDR_TTALE_GTEMP_A + OFFSET_NOR_RAM
#define RAM_ADDR_TTALe_GTEMP_I						FLASH_ADDR_TTALE_GTEMP_I + OFFSET_NOR_RAM

//#define RAM_ADDR_STATIC_DEMO_2						FLASH_ADDR_STATIC_DEMO_2 + OFFSET_NOR_RAM

//FRAME BUFFERS
enum
{
 FB1	= 1,
 FB2,
 FB3,	
 FB4
};

#define	FB_SPLASH					FB4
#define	FB_PARK						FB_SPLASH
#define	FB_NOT_IN_PARK		FB_SPLASH
#define	FB_GEN_PASS_ENTRY	FB1
#define	FB_GEN_START_1		FB1
#define	FB_GEN_START_2		FB1
#define	FB_GEN_START_3		FB1
#define	FB_GEN_START_4		FB1
#define	FB_GEN_START_5		FB1
#define	FB_GEN_START_6		FB1
#define	FB_GEN_SHUT_INT		FB1
#define	FB_GEN_SHUT_EXT		FB1
#define	FB_EXT_GEN_OFF		FB1
#define	FB_SET_PASS_ENTRY	FB1
#define	FB_DEFAULT_RUN		FB1
#define	FB_VECH_STATUS		FB1
#define	FB_SET_SELECT_OP	FB1
#define	FB_SET_SELECT_EXP	FB1
#define	FB_SET_SELECT_DEV	FB1
#define	FB_SET_OP					FB1
#define	FB_SET_EXP				FB1
#define	FB_SET_DEV_1			FB1
#define	FB_SET_DEV_2			FB1
#define	FB_SET_DEV_3			FB1
#define	FB_SET_UNIT				FB1
#define	FB_SET_BRIGHT			FB1
#define	FB_SET_TIME				FB1
#define	FB_SET_MODE				FB1
#define	FB_SET_DATA_READ	FB1
#define	FB_SET_SYS_INFO		FB1
#define	FB_SET_DTC				FB1
#define	FB_SET_GEN_SHUT		FB1
#define	FB_SET_AVR				FB1


// ACP Colors
#define ACP_YELLOW					0xFFE0
#define HPEV_DARK_GREY			0x18C5
#define ACP_LIGHT_GREY			0xCE38
#define ACP_RED							0xE8C4
#define ACP_GREEN						0x37E6
#define ACP_ORANGE					0xF4A4
#define ACP_BLUE						0x025F
#define ACP_GAUGE_GREY			0x8430

// standard colors
#define BLACK								0x0000	
#define NAVY								0x000F    
#define DARK_GREEN					0x03E0    
#define DARK_CYAN						0x03EF    
#define MAROON							0x7800    
#define PURPLE							0x780F    
#define OLIVE								0x7BE0    
#define LIGHT_GRAY					0xC618    
#define DARK_GRAY						0x7BEF  
#define BLUE								0x001F  
#define GREEN								0x07E0  
#define CYAN          			0x07FF  
#define RED           			0xF800  
#define MAGENTA							0xF81F  
#define YELLOW							0xFFE0  
#define WHITE								0xFFFF  
#define	ORANGE							0xFDE0

// New Color Palette
#define GREY_1				0xE71C
#define GREY_2				0xC638
#define GREY_3				0xAD55
#define GREY_4				0x8C71
#define GREY_5				0x738E
#define GREY_6				0x52AA
#define GREY_7				0x39C7
#define GREY_8				0x18E3
				
#define TEAL_1				0xDFFF
#define TEAL_2				0x97FD
#define TEAL_3				0x4FFC
#define TEAL_4				0x07FA
#define TEAL_5				0x06D6
#define TEAL_6				0x05B3
#define TEAL_7				0x04AF
#define TEAL_8				0x03AC
#define TEAL_9				0x02A8
#define TEAL_10				0x0185

#define	GREEN_A_1		0xDFFD
#define	GREEN_A_2		0xA7FA
#define	GREEN_A_3		0x6FF6
#define	GREEN_A_4		0x3FF3
#define	GREEN_A_5		0x07EF
#define	GREEN_A_6		0x068D
#define	GREEN_A_7		0x054A
#define	GREEN_A_8		0x03E7
#define	GREEN_A_9		0x0285
#define	GREEN_A_10	0x0122
			
#define	GREEN_B_1		0xDFFB
#define	GREEN_B_2		0xA7F4
#define	GREEN_B_3		0x6FED
#define	GREEN_B_4		0x3FE7
#define	GREEN_B_5		0x07E0
#define	GREEN_B_6		0x06A0
#define	GREEN_B_7		0x0560
#define	GREEN_B_8		0x0420
#define	GREEN_B_9		0x02C0
#define	GREEN_B_10	0x0180
			
#define	GREEN_C_1		0xEFFB
#define	GREEN_C_2		0xD7F4
#define	GREEN_C_3		0xB7ED
#define	GREEN_C_4		0x9FE7
#define	GREEN_C_5		0x7FE0
#define	GREEN_C_6		0x6EC0
#define	GREEN_C_7		0x5D80
#define	GREEN_C_8		0x4460
#define	GREEN_C_9		0x3320
#define	GREEN_C_10	0x19E0

#define	YELLOW_1		0xFFFB
#define	YELLOW_2		0xFFF2
#define	YELLOW_3		0xFFE9
#define	YELLOW_4		0xFFE0
#define	YELLOW_5		0xDEC0
#define	YELLOW_6		0xB5A0
#define	YELLOW_7		0x94A0
#define	YELLOW_8		0x73A0
#define	YELLOW_9		0x52A0
#define	YELLOW_10		0x3180
			
#define	ORANGE_1		0xFFBB
#define	ORANGE_2		0xFF55
#define	ORANGE_3		0xFEF0
#define	ORANGE_4		0xFEAA
#define	ORANGE_5		0xFE45
#define	ORANGE_6		0xFDE0
#define	ORANGE_7		0xCCC0
#define	ORANGE_8		0x9B80
#define	ORANGE_9		0x6260
#define	ORANGE_10		0x3120
			
#define	RED_ORANGE_1		0xFF5B
#define	RED_ORANGE_2		0xFEB5
#define	RED_ORANGE_3		0xFE10
#define	RED_ORANGE_4		0xFD4A
#define	RED_ORANGE_5		0xFCA5
#define	RED_ORANGE_6		0xFBE0
#define	RED_ORANGE_7		0xD340
#define	RED_ORANGE_8		0xA280
#define	RED_ORANGE_9		0x71C0
#define	RED_ORANGE_10		0x38E0
			
#define	RED_A_1			0xFF1B
#define	RED_A_2			0xFE15
#define	RED_A_3			0xFD10
#define	RED_A_4			0xFC0A
#define	RED_A_5			0xFB05
#define	RED_A_6			0xF9E0
#define	RED_A_7			0xD1A0
#define	RED_A_8			0xA940
#define	RED_A_9			0x78E0
#define	RED_A_10		0x4880
			
#define	RED_B_1			0xFEDB
#define	RED_B_2			0xFD75
#define	RED_B_3			0xFC10
#define	RED_B_4			0xFAAA
#define	RED_B_5			0xF945
#define	RED_B_6			0xF800
#define	RED_B_7			0xD000
#define	RED_B_8			0xA000
#define	RED_B_9			0x7000
#define	RED_B_10		0x3800
			
#define	MAGENTA_1		0xFEDD
#define	MAGENTA_2		0xFD7A
#define	MAGENTA_3		0xFC18
#define	MAGENTA_4		0xFAB5
#define	MAGENTA_5		0xF952
#define	MAGENTA_6		0xF80F
#define	MAGENTA_7		0xC80C
#define	MAGENTA_8		0x9809
#define	MAGENTA_9		0x6006
#define	MAGENTA_10	0x3003
			
#define	PURPLE_1		0xFEDF
#define	PURPLE_2		0xFD1F
#define	PURPLE_3		0xFB7F
#define	PURPLE_4		0xF9DF
#define	PURPLE_5		0xF81F
#define	PURPLE_6		0xD01A
#define	PURPLE_7		0xA815
#define	PURPLE_8		0x8010
#define	PURPLE_9		0x580B
#define	PURPLE_10		0x3006
			
#define	BLUE_PURPLE_1		0xEEDF
#define	BLUE_PURPLE_2		0xD57F
#define	BLUE_PURPLE_3		0xC41F
#define	BLUE_PURPLE_4		0xAABF
#define	BLUE_PURPLE_5		0x915F
#define	BLUE_PURPLE_6		0x781F
#define	BLUE_PURPLE_7		0x6019
#define	BLUE_PURPLE_8		0x4813
#define	BLUE_PURPLE_9		0x300C
#define	BLUE_PURPLE_10	0x1806
			
#define	BLUE_A_1		0xDEDF
#define	BLUE_A_2		0xAD7F
#define	BLUE_A_3		0x841F
#define	BLUE_A_4		0x52BF
#define	BLUE_A_5		0x295F
#define	BLUE_A_6		0x001F
#define	BLUE_A_7		0x001A
#define	BLUE_A_8		0x0014
#define	BLUE_A_9		0x000E
#define	BLUE_A_10		0x0007
			
#define	BLUE_B_1		0xDF3F
#define	BLUE_B_2		0xAE5F
#define	BLUE_B_3		0x855F
#define	BLUE_B_4		0x547F
#define	BLUE_B_5		0x2B9F
#define	BLUE_B_6		0x02BF
#define	BLUE_B_7		0x0239
#define	BLUE_B_8		0x0193
#define	BLUE_B_9		0x010C
#define	BLUE_B_10		0x0086
			
#define	LIGHT_BLUE_1		0xDF9F
#define	LIGHT_BLUE_2		0xA71F
#define	LIGHT_BLUE_3		0x6E7F
#define	LIGHT_BLUE_4		0x3DFF
#define	LIGHT_BLUE_5		0x055F
#define	LIGHT_BLUE_6		0x047A
#define	LIGHT_BLUE_7		0x0395
#define	LIGHT_BLUE_8		0x02D0
#define	LIGHT_BLUE_9		0x01EB
#define	LIGHT_BLUE_10		0x0106

//HPEV
#define COL_HPEV_GREEN_GREY 				0x53CE
#define COL_CGAUGE_LABELS 					COL_HPEV_GREEN_GREY
#define COL_HPEV_GREEN_LIGHT 				0x0E52
#define COL_HPEV_GREEN_DARK 				0x1267
#define COL_BUTTON_ENABLE_BORDER 		COL_HPEV_GREEN_LIGHT
#define COL_BUTTON_ENABLE_FILL 			COL_HPEV_GREEN_DARK
#define COL_GREY_35 								0x5ACB
#define COL_GREY_25 								0x4208
#define COL_GREY_15 								0x2124
#define COL_BUTTON_DISABLE_BORDER 	COL_GREY_35
#define COL_BUTTON_DISABLE_FILL 		COL_GREY_25
#define COL_BUTTON_DISABLE_CONTENT	COL_GREY_15
#define COL_CGAUGE_ORANGE 					0xF4A4
#define COL_CGAUGE_VALUE 						0xCE38

#define DISPLAY_WIDTH  			800
#define DISPLAY_HEIGHT 			480
#define DISPLAY_WIDTH_DOUBLE	DISPLAY_WIDTH*2


#define STYLE_SOLID				0	
#define STYLE_ALPHA				1

/*********************************************************************************************
	3.	TYPE DEFINITIONS
*********************************************************************************************/


/*********************************************************************************************
	4.	ENUMERATIONS
*********************************************************************************************/
enum
{
	FONT_MENTONE_42 = 0,
	FONT_MENTONE_46,
	FONT_MENTONE_92,
	FONT_MENTONE_19,
	FONT_MENTONE_28,


	MENTONE_13,
	MENTONE_68,
	MENTONE_31,
	MENTONE_21,
	MENTONE_31_MONO,
	MENTONE_21_MONO
};				   

enum //Font alignments
{
	LEFT_ALIGN = 0,
	RIGHT_ALIGN,
	CENTER_ALIGN
};		  

/*********************************************************************************************
	5.	STRUCTURES
*********************************************************************************************/

/*********************************************************************************************
	6.	EXTERNAL VARIABLES
*********************************************************************************************/
extern tU8 ActiveFB;

/*********************************************************************************************
	7.	CONSTANTS
*********************************************************************************************/

/*********************************************************************************************
	8.	MACROS
*********************************************************************************************/


/*********************************************************************************************
	9.	FUNCTION PROTOTYPES
*********************************************************************************************/
void lcd_fillScreen(tU8 fb,lcd_color_t color);
void lcd_point(tU32 buf_start_address,tU16 x, tU16 y, lcd_color_t color);
void lcd_point_slow(tU8 fb, tU16 x, tU16 y, lcd_color_t color);
void lcd_drawRect(tU8 fb,tU16 x0, tU16 y0, tU16 x1, tU16 y1, lcd_color_t color);
void lcd_fillRect(tU8 fb,tU16 x0, tU16 y0, tU16 x1, tU16 y1, lcd_color_t color);
void lcd_drawBlankButton(tU8 fb, tU16 x0, tU16 y0, tU16 x1, tU16 y1, lcd_color_t bcolor, lcd_color_t fcolor);
void lcd_line(tU8 fb,tU16 x0, tU16 y0, tU16 x1, tU16 y1, lcd_color_t color);
void lcd_circle(tU8 fb,tU16 x0, tU16 y0, tU16 r, lcd_color_t color);
void lcd_fillcircle(tU8 fb,tU16 x0, tU16 y0, tU16 r, lcd_color_t color);
tBool lcd_putChar(tU8 fb,tU16, tU16, tU8, tU8);
tBool lcd_putCharSolid(tU8 fb,tU16, tU16, tU8, tU8);
void lcd_fontColor(lcd_color_t foreground, lcd_color_t background);
void lcd_picture(tU8 fb,tU16 x, tU16 y, tU16 width, tU16 height, tU16 *pPicture);
void lcd_picture_16(tU8 fb, tU16 x, tU16 y, tU16 width, tU16 height, tU16 *pPicture);
void lcd_picture_32(tU8 fb, tU16 x, tU16 y, tU16 width, tU16 height, tU16 *pPicture);
void lcd_drawTelltale(tU8 fb, tTelltale tt_struct);
void vLine(tU8 fb,tU16, tU16, tU16, lcd_color_t);
void hLine(tU8 fb,tU16 x0, tU16 y0, tU16 x1, lcd_color_t color); 
void lcd_putString(tU8 fb,tU16 x, tU16 y, tU8 *pStr, tU8 style, tU8 font);
void lcd_putNumber(tU8 fb,tU16 x, tU16 y, tS32 integer, tU8 style, tU8 font);
void my_lcd_line(tU8 fb, tU16 x0, tU16 y0,tU16 x1, tU16 y1, lcd_color_t color);
void lcd_switchFB(tU8 fb);
tU32 fb_select(tU8 fb);
void lcd_redraw_number(tU8 fb, tU16 old, tU16 new, tU16 x, tU16 y, lcd_color_t background, lcd_color_t foreground, tU8 font);
void mugui_lcd_puts(tU8 fb, tU16 x, tU16 y, tU8 distance, tU8 *s, tU8 style, tU8 font_name, tU8 align, lcd_color_t background, lcd_color_t foreground);
tU16 mugui_lcd_putc(tU8 fb, tU16 x, tU16 y, tU8 c, tU8 style, tU8 font_name, lcd_color_t background, lcd_color_t foreground);
void mugui_lcd_putNumber(tU8 fb,tU16 x, tU16 y, tU8 distance, tS32 integer, tU8 style, tU8 font_name, tU8 align, lcd_color_t background, lcd_color_t foreground);
void mugui_lcd_putDecimalNumber(tU8 fb,tU16 x, tU16 y, tU8 distance, tS32 integer, tU8 decimal, tU8 style, tU8 font_name, tU8 align, lcd_color_t background, lcd_color_t foreground);
void mugui_lcd_puts_vert(tU8 fb, tU16 x, tU16 y, tU8 distance, tU8 *s, tU8 style, tU8 font_name,/* tU8 align , */lcd_color_t background, lcd_color_t foreground);
void mugui_lcd_updateNumber(tU8 fb,tU16 x, tU16 y, tU8 distance, tS32 old_integer, tS32 new_integer, tU8 style, tU8 font_name, tU8 align, lcd_color_t background, lcd_color_t foreground);
void mugui_lcd_updateDecimalNumber(tU8 fb,tU16 x, tU16 y, tU8 distance, tS32 old_integer, tS32 new_integer, tU8 decimal, tU8 style, tU8 font_name, tU8 align, lcd_color_t background, lcd_color_t foreground);
tU16 mugui_text_sizestring(tU8 *s, tU8 font_name, tU8 distance);
void mugui_lcd_updateNumber(tU8 fb,tU16 x, tU16 y, tU8 distance, tS32 old_integer, tS32 new_integer, tU8 style, tU8 font_name, tU8 align, lcd_color_t background, lcd_color_t foreground);
void mugui_lcd_updateDecimalNumber(tU8 fb,tU16 x, tU16 y, tU8 distance, tS32 old_integer, tS32 new_integer, tU8 decimal, tU8 style, tU8 font_name, tU8 align, lcd_color_t background, lcd_color_t foreground);
tU8* font_select(tU8 font_name);
CustomGauge CreateGaugeCoord(tU16 x0, tU16 y0, tU16 inner, tU16 outer, tS16);
CustomGauge CreateBaseGauge(tU16 inner, tU16 outer, tU16 trim, tS16 angle);
void my_lcd_line_2(tU8 fb, tU16 x0, tU16 y0,tU16 x1, tU16 y1, lcd_color_t color);
void my_lcd_point_plus(tU8 fb,tU16 x, tU16 y, lcd_color_t color);
void drawGauge(tU8 fb,tU16 x, tU16 y, CustomGauge gCData);
void lcd_equil_tri(tU8 fb, tU16 x, tU16 y, tU16 side, lcd_color_t color);
lcd_color_t RGB_Blend(lcd_color_t background_original, lcd_color_t foreground_original, tU8 foreground_intensity);

#endif /* _LCD_GRPH_ */

