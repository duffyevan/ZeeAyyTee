	case 0x20:
		//jr nz, *
		
		pc++
		return 0;

	case 0x21:
		//ld hl, **
		
		pc++
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

