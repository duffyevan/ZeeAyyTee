/*****************************
Known Issues
	~ No RC or IV // I don't know what they do yet so I cant write code for them
	~ I will not be implementing the extended set just yet since its going to quadruple my work
	~ Error codes tell you near where the program failed, not always exactly on the instruction
	~ Flags have not really been implemented yet
*****************************/
byte a;
byte cc;
unsigned short bc;
unsigned short de;
unsigned short sp;
unsigned short pc;
unsigned short ix;
unsigned short iy;
byte flags; //S,Z,AC,P/O,N,C,IE,IM

int ramSize = 4096;
byte ram[ramSize]; // ALL DISKS MUST BE IN BYTES AS A MULTIPLE OF 16

void setup(){
	clearRam();
	Serial.begin(9600);
	Serial.println("Welcome to Zee Ayy Tee");
	Serial.println("A 8080 Emulator Running on AVR");
	Serial.println("Brought to you by Evan Duffy");
	Serial.println("Release Date: ##/##/2016");
	Serial.println("Version 0.1a (Aka I literally just started)");
	Serial.println("Initializing Registers...")
	pc = 0;
	a = 0xFF;
	cc = 0xFF;
	sp = 0xFFFF;
	bc = 0;
	de = 0;
	hl = 0;
	ix = 0;
	iy = 0;
	flags = 0b11111100;
	int freeSpace = findFreeSpace(ram);
	Serial.print("Free RAM: ");
	Serial.print(freeSpace);
	Serial.println(" Bytes");
}

void loop(){
	int error = ifdecodeInstruction();
	switch (error){
		case 1:
			Serial.print("Sorry the instruction near pc = ");
			Serial.print(pc);
			Serial.println(" has not been formatted correctly...");
			while (1);
			break;
		case 2:
			Serial.print("Sorry the instruction near pc = ");
			Serial.print(pc);
			Serial.println(" has not yet been implemented...");
			while (1);
			break;
	}
}

int decodeInstruction(){ // Returns 0 if instruction executed successfully, 1 if there was a problem in format, 2 if the instruction is not supported yet
	byte instruction = ram[pc];
	switch (instruction){
	case 0x00:
		//NO OP
		return 0;
	case 0x01:
		//LD BC, **
		bc = ram[++pc] | (ram[++pc] << 8);
		pc ++;
		return 0;
	case 0x02:
		//LD (BC), A
		ram[bc] = a;
		pc ++;
		return 0;
	case 0x03:
		//INC BC
		bc ++;
		pc ++;
		return 0;
	case 0x04:
		//INC B
		bc += (1 << 8);
		pc ++;
		return 0;
	case 0x05:
		//DEC B
		bc -= (1 << 8);
		pc ++;
		return 0;
	case 0x06:
		//LD B,*
		bc &= (ram[++pc]<<8)
		pc ++;
		return 0;
	case 0x07:
		//LD RCLA
		flags |= ((a >> 7) & 1) << 2;
		a = (a << 1) | ((flags>>2)&1)
		pc ++;
		return 0;
	case 0x08:
		//EX, AF,'AF
		//IDK WHAT AF IS
		return 2;
	case 0x09:
		//ADD HL,BC
		hl+=bc;
		pc ++;
		return 0;
	case 0x0A:
		//LD (BC), A
		ram[bc] = a;
		pc ++;
		return 0;
	case 0x0B:
		//DEC BC
		bc--;
		if (bc == 0xFFFF)
			setFlag("c", 1);
		else
			setFlag("c", 0);
		pc ++;
		return 0;
	// case 0x0C:
	// 	//INC C
	// 	bc &= (bc+1) & 0xFF
	// 	pc ++;
	// 	return 0;
	// case 0x0D:
	// 	//DEC C
	// 	byte c =  
	// 	(bc-1) & 0xFF
	// 	pc ++;
	// 	return 0;
	case 0x0E:
		//LD C, *
		bc = 
		pc ++;
		return 0;
	case 0x0F:
		//INC C
		bc &= (bc+1) & 0xFF
		pc ++;
		return 0;
    
    case 0x10:
        //DJNZ, *
        
        return 0;

    case 0x11:
        //LD DE, **
        de = [++pc];
        pc++;
        return 0;

    case 0x12:
        //LD (DE), A
        ram[de] = a;
        pc++;
        return 0;

    case 0x13:
        //INC DE
        de++;
        pc++;
        return 0;

    case 0x14:
        //INC D
        
        return 0;

    case 0x15:
        //DEC D
        de-= 1<<8;
        return 0;

    case 0x16:
        //LD D, *
        de &= 0xFF;
        de += (ram[++pc]<<8)
        return 0;

    case 0x17:
        //RLA
        
        return 0;

    case 0x18:
        //JR *
        signed char jr = ram[pc++];
        pc += jr;
        return 0;

    case 0x19:
        //ADD HL, DE
        hl += de;
        pc++;
        return 0;

    case 0x1a:
        //LD A, (DE)
        a = ram[de];
        pc++;
        return 0;

    case 0x1b:
        //DEC DE
        de--;
        pc++;
        return 0;

    case 0x1c:
        //INC E
        
        return 0;

    case 0x1d:
        //DEC E
        
        return 0;

    case 0x1e:
        //LD E, *
        de &= 0xFF<<8;
        de += ram[++pc];
        pc++;
        return 0;

    case 0x1f:
        //RRA
        
        return 0;

    case 0x20:
        //jr nz, *
        
        pc++
        return 0;

    case 0x21:
        //ld hl, **
        hl = ram[++pc];
        pc++;
        return 0;

    case 0x22:
        //ld (**), hl
        
        pc++
        return 0;

    case 0x23:
        //inc hl
        
        pc++
        return 0;

    case 0x24:
        //inc h
        
        pc++
        return 0;

    case 0x25:
        //dec h
        
        pc++
        return 0;

    case 0x26:
        //ld h,*
        
        pc++
        return 0;

    case 0x27:
        //daa
        
        pc++
        return 0;

    case 0x28:
        //jr z, *
        
        pc++
        return 0;

    case 0x29:
        //add hl,hl
        
        pc++
        return 0;

    case 0x2a:
        //ld hl, (**)
        
        pc++
        return 0;

    case 0x2b:
        //dec hl
        
        pc++
        return 0;

    case 0x2c:
        //inc l
        
        pc++
        return 0;

    case 0x2d:
        //dec l
        
        pc++
        return 0;

    case 0x2e:
        //ld l, *
        
        pc++
        return 0;

    case 0x2f:
        //cpl
        
        pc++
        return 0;




	}
	return 2
}

void printRegisters(){
	print("pc: ");
	println(hex(pc));
	print("cc: ");
	println(cc);
	print("a: ");
	println(hex(a));
	print("bc: ");
	println(hex(bc));
	print("de: ");
	println(hex(de));
	print("hl: ");
	println(hl);
	print("sp: ");
	println(hex(sp));
	print("ix: ");
	println(hex(ix));
	print("iy: ");
	println(hex(iy));
}

void printDisk(byte* disk, int length){
	int i = 0;
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	Serial.print(" ");
	Serial.print(hex(i++));
	
	for (i = 0; i < length; i+=16){
		Serial.print(hex(i));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
		Serial.print(" ");
		Serial.print(hex(disk[i++]));
	}
}

int findFreeSpace(byte* disk,  int length){
	int cntr = length;
	while(disk[cntr] == 0 && cntr <= 0)
		cntr--;
	return length - cntr;
}

void clearRam(){
	int cntr = 0;
	while (cntr < ram.length()){
		ram[cntr] = 0;
		cntr++;
	}
}
