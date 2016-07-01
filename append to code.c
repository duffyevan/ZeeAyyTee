	case 0x30:
		//jr nc,*
		signed char jump = ram[++pc];
		if (!c)
			pc += jump;
		return 0;

	case 0x31:
		//ld sp,**
		sp = ram[++pc] + (ram[++pc]<<8);
		return 0;

	case 0x32:
		//ld (**),a
		ram[++pc] = a;
		return 0;

	case 0x33:
		//inc sp
		sp++;
		return 0;

	case 0x34:
		//inc (hl)
		ram[hl]++;
		return 0;

	case 0x35:
		//dec (hl)
		ram[hl]--;
		return 0;

	case 0x36:
		//ld (hl),*
		ram[hl] = ram[++pc];
		return 0;

	case 0x37:
		//scf
		
		return 0;

	case 0x38:
		//jr c,*
		signed char jump = ram[++pc];
		if (c)
			pc += jump;
		return 0;

	case 0x39:
		//add hl,sp
		hl += sp;
		return 0;

	case 0x3a:
		//ld a,(**)
		a = ram[ram[++pc] + (ram[++pc]<<8)]; 
		return 0;

	case 0x3b:
		//dec sp
		sp--;
		return 0;

	case 0x3c:
		//inc a
		a++;
		return 0;

	case 0x3d:
		//dec a
		a--;
		return 0;

	case 0x3e:
		//ld a,*
		a = ram[++pc];
		return 0;

	case 0x3f:
		//ccf
		c = !c;
		return 0;

	case 0x40:
		//ld b,b
		// I don't think I need to do anything here
		return 0;

	case 0x41:
		//ld b,c
		byte c = (byte)(bc && 0xff);
		bc = c + (c<<8);
		return 0;

	case 0x42:
		//ld b,d
		byte d = (byte)(de>>8);
		bc &= 0xFF;
		bc += d<<8;
		return 0;

	case 0x43:
		//ld b,e
		byte e = (byte)(de&0xff);
		bc &= 0xFF;
		bc += e<<8;
		return 0;

	case 0x44:
		//ld b,h
		byte h = (byte)(hl>>8);
		bc &= 0xFF;
		bc += h<<8;
		return 0;

	case 0x45:
		//ld b,l
		
		return 0;

	case 0x46:
		//ld b, (hl)
		
		return 0;

	case 0x47:
		//ld b,a
		
		return 0;

	case 0x48:
		//ld c,b
		
		return 0;

	case 0x49:
		//ld c,c
		
		return 0;

	case 0x4a:
		//ld c,d
		
		return 0;

	case 0x4b:
		//ld c,e
		
		return 0;

	case 0x4c:
		//ld c,h
		
		return 0;

	case 0x4d:
		//ld c,l
		
		return 0;

	case 0x4e:
		//ld c,(hl)
		
		return 0;

	case 0x4f:
		//ld c,a
		
		return 0;

