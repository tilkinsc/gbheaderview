
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


static char* get_cgb_flag(uint8_t flag) {
	switch(flag) {
		case 0x00:
			return "(GB Only)";
		case 0xC0:
			return "(CGB Only)";
		case 0x80:
			return "(CGB and GB)";
	}
	return "(Invalid)";
}

static char* get_new_lic_code(uint8_t x, uint8_t y) {
	switch(x) {
		case '0':
			switch(y) {
				case '0':
					return "(None)";
				case '1':
					return "(Nintendo)";
				case '8':
					return "(Capcom)";
			}
		case '1':
			switch(y) {
				case '3':
					return "(Electronic Arts)";
				case '8':
					return "(Hudsonsoft)";
				case '9':
					return "(b-ai)";
			}
		case '2':
			switch(y) {
				case '0':
					return "(Kss)";
				case '2':
					return "(Pow)";
				case '4':
					return "(PCM Complete)";
				case '5':
					return "(San-X)";
				case '8':
					return "(Kemco Japan)";
				case '9':
					return "(Seta)";
			}
		case '3':
			switch(y) {
				case '0':
					return "(Viacom)";
				case '1':
					return "(Nintendo)";
				case '2':
					return "(Bandia)";
				case '3':
					return "(Ocean/Acclaim)";
				case '4':
					return "(Konami)";
				case '5':
					return "(Hector)";
				case '7':
					return "(Taito)";
				case '8':
					return "(Hudson)";
				case '9':
					return "(Banpresto)";
			}
		case '4':
			switch(y) {
				case '1':
					return "(UBI Soft)";
				case '2':
					return "(Atlus)";
				case '4':
					return "(Malibu)";
				case '6':
					return "(Angel)";
				case '7':
					return "(Pullet-Proof)";
				case '9':
					return "(Irem)";
			}
		case '5':
			switch(y) {
				case '0':
					return "(Absolute)";
				case '1':
					return "(Acclaim)";
				case '2':
					return "(Activision)";
				case '3':
					return "(American Sammy)";
				case '4':
					return "(Konami)";
				case '5':
					return "(Hi Tech Entertainment)";
				case '6':
					return "(ljn)";
				case '7':
					return "(Matchbox)";
				case '8':
					return "(Mattel)";
				case '9':
					return "(Milton Bradley)";
			}
		case '6':
			switch(y) {
				case '0':
					return "(Titus)";
				case '1':
					return "(Virgin)";
				case '4':
					return "(Lucasarts)";
				case '7':
					return "(Ocean)";
				case '9':
					return "(Electronic Arts)";
			}
		case '7':
			switch(y) {
				case '0':
					return "(Infogrames)";
				case '1':
					return "(Interplay)";
				case '2':
					return "(Broderbund)";
				case '3':
					return "(Sculptured)";
				case '5':
					return "(SCI)";
				case '8':
					return "(T*HQ)";
				case '9':
					return "(Accolade)";
			}
		case '8':
			switch(y) {
				case '0':
					return "(Misawa)";
				case '3':
					return "(Lozc)";
				case '6':
					return "(Tokuma Shoten i*)";
				case '7':
					return "(Tsukuda Ori*)";
			}
		case '9':
			switch(y) {
				case '1':
					return "(Chun Soft)";
				case '2':
					return "(Video System)";
				case '3':
					return "(Ocean/Acclaim)";
				case '5':
					return "(Varie)";
				case '6':
					return "(Yonezawa/S'Pal)";
				case '7':
					return "(Kaneko)";
				case '9':
					return "(Pack In Soft)";
			}
		//
	}
	return "(Invalid)";
}

static char* get_sgb_flag(uint8_t flag) {
	switch(flag) {
		case 0x00:
			return "(No SGB Functions)";
		case 0x03:
			return "(SGB Functions)";
	}
	return "(Invalid)";
}

static char* get_cart_type(uint8_t flag) {
	switch(flag) {
		case 0x00:
			return "(ROM ONLY)";
		case 0x01:
			return "(MBC1)";
		case 0x02:
			return "(MBC1+RAM)";
		case 0x03:
			return "(MBC1+RAM+BATTERY)";
		case 0x05:
			return "(MBC2)";
		case 0x06:
			return "(MBC2+BATTERY)";
		case 0x08:
			return "(ROM+RAM)";
		case 0x09:
			return "(ROM+RAM+BATTERY)";
		case 0x0B:
			return "(MMM01)";
		case 0x0C:
			return "(MMM01+RAM)";
		case 0x0D:
			return "(MMM01+RAM+BATTERY)";
		case 0x0F:
			return "(MBC3+TIMER+BATTERY)";
		case 0x10:
			return "(MBC3+TIMER+RAM+BATTERY)";
		case 0x11:
			return "(MBC3)";
		case 0x12:
			return "(MBC3+RAM)";
		case 0x13:
			return "(MBC3+RAM+BATTERY)";
		case 0x15:
			return "(MBC4)";
		case 0x16:
			return "(MBC4+RAM)";
		case 0x17:
			return "(MBC4+RAM+BATTERY)";
		case 0x19:
			return "(MBC5)";
		case 0x1A:
			return "(MBC5+RAM)";
		case 0x1B:
			return "(MBC5+RAM+BATTERY)";
		case 0x1C:
			return "(MBC5+RUMBLE)";
		case 0x1D:
			return "(MBC5+RUMBLE+RAM)";
		case 0x1E:
			return "(MBC5+RUMBLE+RAM+BATTERY)";
		case 0xFC:
			return "(POCKET CAMERA)";
		case 0xFD:
			return "(BANDAI TAMA5)";
		case 0xFE:
			return "(HuC3)";
		case 0xFF:
			return "(HuC1+RAM+BATTERY)";
	}
	return "(Invalid)";
}

static char* get_rom_size(uint8_t flag) {
	switch(flag) {
		case 0x00:
			return "(32KByte (no ROM banking))";
		case 0x01:
			return "(64KByte (4 banks))";
		case 0x02:
			return "(128KByte (8 banks))";
		case 0x03:
			return "(256KByte (16 banks))";
		case 0x04:
			return "(512KByte (32 banks))";
		case 0x05:
			return "(1MByte (64 banks) - only 63 banks used by MBC1)";
		case 0x06:
			return "(2MByte (128 banks) - only 125 banks used by MBC1)";
		case 0x07:
			return "(4MByte (256 banks))";
		case 0x52:
			return "(1.1MByte (72 banks))";
		case 0x53:
			return "(1.2MByte (80 banks))";
		case 0x54:
			return "(1.5MByte (96 banks))";
	}
	return "(Invalid)";
}

static char* get_ram_size(uint8_t flag) {
	switch(flag) {
		case 0x00:
			return "(None)";
		case 0x01:
			return "(2 KByte)";
		case 0x02:
			return "(8 KByte)";
		case 0x03:
			return "(32 KByte (4 banks * 8 KByte))";
	}
	return "(Invalid)";
}

static char* get_destination(uint8_t flag) {
	switch(flag) {
		case 0x00:
			return "(Japanese)";
		case 0x01:
			return "(Non-Japanese)";
	}
	return "(Invalid)";
}

static char* get_old_licensee_code(uint8_t flag) {
	switch(flag) {
		case 0x00:
			return "(None)";
		case 0x01:
			return "(Nintendo)";
		case 0x08:
			return "(Capcom)";
		case 0x09:
			return "(Hot-b)";
		case 0x0A:
			return "(Jaleco)";
		case 0x0B:
			return "(Coconuts)";
		case 0x0C:
			return "(Elite Systems)";
		case 0x13:
			return "(Electronic Arts)";
		case 0x18:
			return "(Hudsonsoft)";
		case 0x19:
			return "(ITC Entertainment)";
		case 0x1A:
			return "(Yanoman)";
		case 0x1D:
			return "(Clary)";
		case 0x1F:
			return "(Virgin)";
		case 0x20:
			return "(KSS)";
		case 0x24:
			return "(PCM Complete)";
		case 0x25:
			return "(San-x)";
		case 0x28:
			return "(Kotobuki Systems)";
		case 0x29:
			return "(Seta)";
		case 0x30:
			return "(Infogrames)";
		case 0x31:
			return "(Nintendo)";
		case 0x32:
			return "(Bandai)";
		case 0x33:
			return "(GBC - See Above)";
		case 0x34:
			return "(Konami)";
		case 0x35:
			return "(Hector)";
		case 0x38:
			return "(Capcom)";
		case 0x39:
			return "(Banpresto)";
		case 0x3C:
			return "(*Entertainment I)";
		case 0x3E:
			return "(Gremlin)";
		case 0x41:
			return "(Ubisoft)";
		case 0x42:
			return "(Atlus)";
		case 0x44:
			return "(Malibu)";
		case 0x46:
			return "(Angel)";
		case 0x47:
			return "(Spectrum Holoby)";
		case 0x49:
			return "(Irem)";
		case 0x4A:
			return "(Virgin)";
		case 0x4D:
			return "(Malibu)";
		case 0x4F:
			return "(U.S. Gold)";
		case 0x50:
			return "(Absolute)";
		case 0x51:
			return "(Acclaim)";
		case 0x52:
			return "(Activision)";
		case 0x53:
			return "(American Sammy)";
		case 0x54:
			return "(Gametek)";
		case 0x55:
			return "(Park Place)";
		case 0x56:
			return "(ljn)";
		case 0x57:
			return "(Matchbox)";
		case 0x59:
			return "(Milton Bradley)";
		case 0x5A:
			return "(Mindscape)";
		case 0x5B:
			return "(Romstar)";
		case 0x5C:
			return "(Naxat Soft)";
		case 0x5D:
			return "(Tradewest)";
		case 0x60:
			return "(Titus)";
		case 0x61:
			return "(Virgin)";
		case 0x67:
			return "(Ocean)";
		case 0x69:
			return "(Electronic Arts)";
		case 0x6E:
			return "(Elite Systems)";
		case 0x6F:
			return "(Electro Brain)";
		case 0x70:
			return "(Infogrammes)";
		case 0x71:
			return "(Interplay)";
		case 0x72:
			return "(Broderbund)";
		case 0x73:
			return "(Sculptered Soft)";
		case 0x75:
			return "(The Sales Curve)";
		case 0x78:
			return "(t*hq)";
		case 0x79:
			return "(Accolade)";
		case 0x7A:
			return "(Triffix Entertainment)";
		case 0x7C:
			return "(Microprose)";
		case 0x7F:
			return "(Kemco)";
		case 0x80:
			return "(Misawa Entertainment)";
		case 0x83:
			return "(lozc)";
		case 0x86:
			return "(Tokuma Shoten Intermedia)";
		case 0x8B:
			return "(Bullet-Proof Software)";
		case 0x8C:
			return "(Vic Tokai)";
		case 0x8E:
			return "(Ape)";
		case 0x8F:
			return "(I'max)";
		case 0x91:
			return "(Chun Soft)";
		case 0x92:
			return "(Video System)";
		case 0x93:
			return "(Tsuburava)";
		case 0x95:
			return "(Varie)";
		case 0x96:
			return "(Yonezawa/S'Pal)";
		case 0x97:
			return "(Kaneko)";
		case 0x99:
			return "(Arc)";
		case 0x9A:
			return "(Nihon Bussan)";
		case 0x9B:
			return "(Tecmo)";
		case 0x9C:
			return "(Imagineer)";
		case 0x9D:
			return "(Banpresto)";
		case 0x9F:
			return "(Nova)";
		case 0xA1:
			return "(Hori Electric)";
		case 0xA2:
			return "(Bandai)";
		case 0xA4:
			return "(Konami)";
		case 0xA6:
			return "(Kawada)";
		case 0xA7:
			return "(Takara)";
		case 0xA9:
			return "(Technos Japan)";
		case 0xAA:
			return "(Broderbund)";
		case 0xAC:
			return "(Toei Animation)";
		case 0xAD:
			return "(Toho)";
		case 0xAF:
			return "(Namco)";
		case 0xB0:
			return "(Acclaim)";
		case 0xB1:
			return "(Ascii or Nexoft)";
		case 0xB2:
			return "(Bandai)";
		case 0xB4:
			return "(Enix)";
		case 0xB6:
			return "(HAL)";
		case 0xB7:
			return "(SNK)";
		case 0xB9:
			return "(Pony Canyon)";
		case 0xBA:
			return "(*Culture Brain O)";
		case 0xBB:
			return "(Sunsoft)";
		case 0xBD:
			return "(Sony Imagesoft)";
		case 0xBF:
			return "(Sammy)";
		case 0xC0:
			return "(Taito)";
		case 0xC2:
			return "(Kemco)";
		case 0xC3:
			return "(Squaresoft)";
		case 0xC4:
			return "(Tokuma Shoten Intermedia)";
		case 0xC5:
			return "(Data East)";
		case 0xC6:
			return "(Tonkin House)";
		case 0xC8:
			return "(Koei)";
		case 0xC9:
			return "(ufl)";
		case 0xCA:
			return "(Ultra)";
		case 0xCB:
			return "(Vap)";
		case 0xCC:
			return "(Use)";
		case 0xCD:
			return "(Meldac)";
		case 0xCE:
			return "(*Pony Canyon)";
		case 0xCF:
			return "(Angel)";
		case 0xD0:
			return "(Taito)";
		case 0xD1:
			return "(Sofel)";
		case 0xD2:
			return "(Quest)";
		case 0xD3:
			return "(Sigma Enterprises)";
		case 0xD4:
			return "(Ask Kodansha)";
		case 0xD6:
			return "(Naxat Soft)";
		case 0xD7:
			return "(Copya Systems)";
		case 0xD9:
			return "(Banpresto)";
		case 0xDA:
			return "(Tomy)";
		case 0xDB:
			return "(ljn)";
		case 0xDD:
			return "(Ncs)";
		case 0xDE:
			return "(Human)";
		case 0xDF:
			return "(Altron)";
		case 0xE0:
			return "(Jaleco)";
		case 0xE1:
			return "(Towachiki)";
		case 0xE2:
			return "(Uutaka)";
		case 0xE3:
			return "(Varie)";
		case 0xE5:
			return "(Epoch)";
		case 0xE7:
			return "(Athena)";
		case 0xE8:
			return "(Asmik)";
		case 0xE9:
			return "(Natsume)";
		case 0xEA:
			return "(King records)";
		case 0xEB:
			return "(Atlus)";
		case 0xEC:
			return "(Epic/Sony Records)";
		case 0xEE:
			return "(Igs)";
		case 0xF0:
			return "(A Wave)";
		case 0xF3:
			return "(Extreme Entertainment)";
		case 0xFF:
			return "(ljn)";
	}
	return "(Invalid)";
}


typedef struct tag_gbinfo {
	
	/* Resets */
	uint8_t rst00h[8]; // reset 00h
	uint8_t rst08h[8]; // reset 08h
	uint8_t rst10h[8]; // reset 10h
	uint8_t rst18h[8]; // reset 18h
	uint8_t rst20h[8]; // reset 20h
	uint8_t rst28h[8]; // reset 28h
	uint8_t rst30h[8]; // reset 30h
	uint8_t rst38h[8]; // reset 38h 64
	
	/* Interrupt Vector */
	uint8_t int40h[8]; // INT 40h
	uint8_t int48h[8]; // INT 48h
	uint8_t int50h[8]; // INT 50h
	uint8_t int58h[8]; // INT 58h
	uint8_t int60h[8]; // INT 60h
	uint8_t int68h[8]; // INT 68h
	uint8_t int70h[8]; // INT 70h
	uint8_t int78h[8]; // INT 78h
	uint8_t int80h[8]; // INT 80h
	uint8_t int88h[8]; // INT 88h
	uint8_t int90h[8]; // INT 90h
	uint8_t int98h[8]; // INT 98h
	uint8_t intA0h[8]; // INT A0h
	uint8_t intA8h[8]; // INT A8h
	uint8_t intB0h[8]; // INT B0h
	uint8_t intB8h[8]; // INT B8h
	uint8_t intC0h[8]; // INT C0h
	uint8_t intC8h[8]; // INT C8h
	uint8_t intD0h[8]; // INT D0h
	uint8_t intD8h[8]; // INT D8h
	uint8_t intE0h[8]; // INT E0h
	uint8_t intE8h[8]; // INT E8h
	uint8_t intF0h[8]; // INT F0h
	uint8_t intF8h[8]; // INT F8h 192
	
	uint8_t entry_point[4]; // Entry Point 100h-103h
	
	
	/*
	  CE ED 66 66 CC 0D 00 0B 03 73 00 83 00 0C 00 0D
	  00 08 11 1F 88 89 00 0E DC CC 6E E6 DD DD D9 99
	  BB BB 67 63 6E 0E EC CC DD DC 99 9F BB B9 33 3E
	*/
	uint8_t dummy[48]; // 104h-133h
	
	uint8_t title[11]; // Title 134h-143h
	
	uint8_t manufacturer[4]; // Manufacturer Code 13Fh-142h
	
	
	/*
	  80h - Supports CGB functions, works on old gbs
	  C0h - CGB only
	  00h - GB only
	*/
	uint8_t cgb_flag; // Gameboy Color Flag 143h
	
	uint8_t new_licensee_code[2]; // New Licensee Code 144h-145h
	
	
	/*
	  00h - No SGB functions
	  03h - Supports SGB functions
	*/
	uint8_t sgb_flag; // SGB Flag 146h
	
	
	/*
	  00h - ROM ONLY                 13h  MBC3+RAM+BATTERY
	  01h - MBC1                     15h  MBC4
	  02h - MBC1+RAM                 16h  MBC4+RAM
	  03h - MBC1+RAM+BATTERY         17h  MBC4+RAM+BATTERY
	  05h - MBC2                     19h  MBC5
	  06h - MBC2+BATTERY             1Ah  MBC5+RAM
	  08h - ROM+RAM                  1Bh  MBC5+RAM+BATTERY
	  09h - ROM+RAM+BATTERY          1Ch  MBC5+RUMBLE
	  0Bh - MMM01                    1Dh  MBC5+RUMBLE+RAM
	  0Ch - MMM01+RAM                1Eh  MBC5+RUMBLE+RAM+BATTERY
	  0Dh - MMM01+RAM+BATTERY        FCh  POCKET CAMERA
	  0Fh - MBC3+TIMER+BATTERY       FDh  BANDAI TAMA5
	  10h - MBC3+TIMER+RAM+BATTERY   FEh  HuC3
	  11h - MBC3                     FFh  HuC1+RAM+BATTERY
	  12h - MBC3+RAM
	*/
	uint8_t cart_type; // Cartridge Type 147h
	
	
	/*
	  00h -  32KByte (no ROM banking)
	  01h -  64KByte (4 banks)
	  02h - 128KByte (8 banks)
	  03h - 256KByte (16 banks)
	  04h - 512KByte (32 banks)
	  05h -   1MByte (64 banks) - only 63 banks used by MBC1
	  06h -   2MByte (128 banks) - only 125 banks used by MBC1
	  07h -   4MByte (256 banks)
	  52h - 1.1MByte (72 banks)
	  53h - 1.2MByte (80 banks)
	  54h - 1.5MByte (96 banks)
	*/
	uint8_t rom_size; // ROM Size 148h
	
	
	/*
	  00h - None
	  01h - 2 KBytes
	  02h - 8 Kbytes
	  03h - 32 KBytes (4 banks of 8KBytes each)
	*/
	uint8_t ram_size; // RAM Size 149h
	
	
	/*
	  00h - Japanese
	  01h - Non-Japanese
	*/
	uint8_t destination_code; // Destination Code 14Ah
	
	uint8_t old_licensee_code; // Old Licensee Code 14Bh
	
	uint8_t rom_version; // Mask Rom Version Number 14Ch
	
	uint8_t header_checksum; // Header Checksum 14Dh
	
	uint8_t global_checksum[2]; // Global Checksum 14Eh-14Fh
	
} __attribute__((aligned(1), packed)) gbinfo;


int32_t main(int32_t argc, char** argv)
{
	
	assert(sizeof(gbinfo) == 336); // should be 336
	
	if(argc <= 1) {
		fprintf(stderr, "Please specify the files you want to pretty print!");
		exit(1);
	}
	
	for(int c=1; c<argc; c++) {
		FILE* fp;
		fp = fopen(argv[1], "rb");
		if(fp == 0) {
			fprintf(stderr, "Could not open file!\n");
			return (int32_t) EXIT_FAILURE;
		}
		
		gbinfo info;
		memset(&info, 0, sizeof(info));
		
		fread(&info, sizeof(info), 1, fp);
		fclose(fp);
		
		uint32_t i;
		printf("rst00h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.rst00h[i]);
		}
		puts("");
		
		printf("rst08h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.rst08h[i]);
		}
		puts("");
		
		printf("rst10h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.rst10h[i]);
		}
		puts("");
		
		printf("rst18h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.rst18h[i]);
		}
		puts("");
		
		printf("rst20h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.rst20h[i]);
		}
		puts("");
		
		printf("rst28h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.rst28h[i]);
		}
		puts("");
		
		printf("rst30h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.rst30h[i]);
		}
		puts("");
		
		printf("rst38h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.rst38h[i]);
		}
		
		
		puts("\n");
		
		
		printf("int40h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int40h[i]);
		}
		puts("");
		
		printf("int48h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int48h[i]);
		}
		puts("");
		
		printf("int50h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int50h[i]);
		}
		puts("");
		
		printf("int58h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int58h[i]);
		}
		puts("");
		
		printf("int60h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int60h[i]);
		}
		puts("");
		
		printf("int68h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int68h[i]);
		}
		puts("");
		
		printf("int70h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int70h[i]);
		}
		puts("");
		
		printf("int78h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int78h[i]);
		}
		puts("");
		
		printf("int80h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int80h[i]);
		}
		puts("");
		
		printf("int88h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int88h[i]);
		}
		puts("");
		
		printf("int90h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int90h[i]);
		}
		puts("");
		
		printf("int98h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.int98h[i]);
		}
		puts("");
		
		printf("intA0h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intA0h[i]);
		}
		puts("");
		
		printf("intA8h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intA8h[i]);
		}
		puts("");
		
		printf("intB0h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intB0h[i]);
		}
		puts("");
		
		printf("intB8h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intB8h[i]);
		}
		puts("");
		
		printf("intC0h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intC0h[i]);
		}
		puts("");
		
		printf("intC8h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intC8h[i]);
		}
		puts("");
		
		printf("intD0h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intD0h[i]);
		}
		puts("");
		
		printf("intD8h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intD8h[i]);
		}
		puts("");
		
		printf("intE0h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intE0h[i]);
		}
		puts("");
		
		printf("intE8h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intE8h[i]);
		}
		puts("");
		
		printf("intF0h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intF0h[i]);
		}
		puts("");
		
		printf("intF8h - ");
		for(i=0; i<8; i++) {
			printf("%.2x ", info.intF8h[i]);
		}
		
		
		puts("\n");
		
		
		printf("Entry Point - ");
		for(i=0; i<4; i++) {
			printf("%.2x ", info.entry_point[i]);
		}
		
		puts("\n");
		
		
		printf("Title - ");
		for(i=0; i<11; i++) {
			printf("%c", info.title[i]);
		}
		
		if(((info.manufacturer[0] > 31 && info.manufacturer[0] < 127) || info.manufacturer[0] == 0x00)
			&& ((info.manufacturer[1] > 31 && info.manufacturer[1] < 127) || info.manufacturer[1] == 0x00)
			&& ((info.manufacturer[2] > 31 && info.manufacturer[2] < 127) || info.manufacturer[2] == 0x00)
			&& ((info.manufacturer[3] > 31 && info.manufacturer[3] < 127) || info.manufacturer[3] == 0x00)
		) {
			for(i=0; i<4; i++) {
				if(info.manufacturer[i] == 0)
					printf("\\0");
				else
					printf("%c", info.manufacturer[i]);
			}
		} else {
			printf(" - Manufacturer - ");
			for(i=0; i<4; i++) {
				printf("%.2x ", info.manufacturer[i]);
			}
		}
		puts("\n");
		
		printf("CGB Flag - %.2x %s\n", info.cgb_flag, get_cgb_flag(info.cgb_flag));
		
		if(info.old_licensee_code == 0x33) {
			printf("New Licensee Code - (ASCII) %c%c %s\n", info.new_licensee_code[0], info.new_licensee_code[1], get_new_lic_code(info.new_licensee_code[0], info.new_licensee_code[1]));
		} else {
			printf("New Licensee Code - (HEX) %.2x %.2x\n", info.new_licensee_code[0], info.new_licensee_code[1]);
		}
		
		printf("SGB Flag - %.2x %s\n", info.sgb_flag, get_sgb_flag(info.sgb_flag));
		
		
		puts("");
		
		printf("Cartridge Type - %.2x %s\n", info.cart_type, get_cart_type(info.cart_type));
		printf("Rom Size - %.2x %s\n", info.rom_size, get_rom_size(info.rom_size));
		printf("Ram Size - %.2x %s\n", info.ram_size, get_ram_size(info.ram_size));
		
		puts("");
		
		printf("Destination Code - %.2x %s\n", info.destination_code, get_destination(info.destination_code));
		printf("Old Licensee Code - %.2x %s\n", info.old_licensee_code, get_old_licensee_code(info.old_licensee_code));
		printf("ROM Version - %.2x\n", info.rom_version);
		
		puts("");
		
		printf("Header Checksum - %.2x\n", info.header_checksum);
		
		printf("Global Checksum - %.2x %.2x\n", info.global_checksum[0], info.global_checksum[1]);
	}
	
	return (int32_t) EXIT_SUCCESS;
}

