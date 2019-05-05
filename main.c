
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



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
	
	uint8_t manufacturer[4]; // Manufacturer Code (only if set below) 13Fh-142h
	
	
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
	  05h -   1MByte (64 banks)  - only 63 banks used by MBC1
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
		
		printf("CGB Flag - %.2x\n", info.cgb_flag);
		
		if(info.old_licensee_code == 0x33) {
			printf("New Licensee Code - (ASCII) %c%c\n", info.new_licensee_code[0], info.new_licensee_code[1]);
		} else {
			printf("New Licensee Code - (HEX) %.2x %.2x\n", info.new_licensee_code[0], info.new_licensee_code[1]);
		}
		
		printf("SGB Flag - %.2x\n", info.sgb_flag);
		
		
		puts("");
		
		printf("Cartridge Type - %.2x\n", info.cart_type);
		printf("Rom Size - %.2x\n", info.rom_size);
		printf("Ram Size - %.2x\n", info.ram_size);
		
		puts("");
		
		printf("Destination Code - %.2x\n", info.destination_code);
		printf("Old Licensee Code - %.2x\n", info.old_licensee_code);
		printf("ROM Version - %.2x\n", info.rom_version);
		
		puts("");
		
		printf("Header Checksum - %.2x\n", info.header_checksum);
		
		printf("Global Checksum - %.2x %.2x\n", info.global_checksum[0], info.global_checksum[1]);
	}
	
	return (int32_t) EXIT_SUCCESS;
}

