#include "Software/Oscilloscope.hpp"

Oscilloscope_Class *Oscilloscope_Class::Instance_Pointer = NULL;

Oscilloscope_Class::Oscilloscope_Class() : Software_Class(Oscilloscope_Handle),
										   Start(false)
{
	Xila.Task.Create(Main_Task, "Oscilloscope", Memory_Chunk(4), NULL, &Task_Handle);
}

Oscilloscope_Class::~Oscilloscope_Class()
{
	if (Instance_Pointer != this)
	{
		delete Instance_Pointer;
	}
	Instance_Pointer = NULL;
}

Software_Class *Oscilloscope_Class::Load()
{
	if (Instance_Pointer != NULL)
	{
		delete Instance_Pointer;
	}
	Instance_Pointer = new Oscilloscope_Class();
	return Instance_Pointer;
}

void Oscilloscope_Class::Main_Task(void *pvParameters)
{

	Instance_Pointer->Loop();
}

void Oscilloscope_Class::Loop()
{
	while (1)
	{
		switch (Get_Instruction())
		{
		case Idle:
			if (Xila.Software.Get_State(Oscilloscope_Handle) == Minimized)
			{
				Xila.Task.Delay(90);
			}
			else
			{
				if (Start)
				{
					Send_Instruction('S', 'a');
				}
				Send_Instruction('T', 'r');
			}
			Xila.Task.Delay(20);
			break;
		case Open:
			Start = false;
			Xila.Display.Set_Current_Page(F("Oscilloscope"));
			Refresh_Interface();
			break;
		case Maximize:
			Start = false;
			Xila.Display.Set_Current_Page(F("Oscilloscope"));
			Refresh_Interface();
			break;
		case Minimize:
			break;
		case Shutdown:
		case Restart:
		case Close:
			delete Instance_Pointer;
			Xila.Task.Delete();
			break;
		case Instruction('k', 'P'):
			if (Current_Channel == 0)
			{
				float Temporary_Float = ad_ch0;
				Xila.Dialog.Keypad(Temporary_Float);
				if (Temporary_Float > 39 || Temporary_Float < 0)
				{
					ad_ch0 = Default_Channel_0_Pin;
				}
				else
				{
					ad_ch0 = (uint8_t)Temporary_Float;
				}
			}
			else if (Current_Channel == 1)
			{
				float Temporary_Float = ad_ch1;
				Xila.Dialog.Keypad(Temporary_Float);
				if (ad_ch1 > 39 || ad_ch1 < 0)
				{
					ad_ch1 = Default_Channel_1_Pin;
				}
				else
				{
					ad_ch1 = (uint8_t)Temporary_Float;
				}
			}
			Send_Instruction('R', 'e');
			break;
		case Instruction('T', 'r'):
			Trigger();
			break;

		case Instruction('S', 'a'):
			Sampling();
			break;
		case Instruction('R', 'W'): // refresh waveform
			Refresh_Waveform();
			break;
		case Instruction('R', 'e'):
			Refresh_Interface();
			break;
		case Instruction('C', 'l'):
			Start = false;
		Xila.Software.Close(Oscilloscope_Handle);
			break;
		case Instruction('M', 'i'):
			Start = false;
			Xila.Software.Minimize(Oscilloscope_Handle);
			break;
		case Instruction('S', 't'): // SA : Start
			Start = !Start;
			Send_Instruction('R', 'e');
			break;

		case Instruction('N', 'C'): // next channel
			if (Current_Channel == 0)
			{
				Current_Channel = 1;
			}
			else
			{
				Current_Channel = 0;
			}
			Send_Instruction('R', 'e');
			break;
		case Instruction('P', 'C'): // previous channel
			if (Current_Channel == 1)
			{
				Current_Channel = 0;
			}
			else
			{
				Current_Channel = 1;
			}
			Send_Instruction('R', 'e');
			break;
		case Instruction('R', '-'):
			if (Current_Channel == 0)
			{
				if (range0 < RANGE_MAX)
				{
					range0++;
				}
			}
			else
			{
				if (range1 < RANGE_MAX)
				{
					range1++;
				}
			}
			Send_Instruction('R', 'e');
			break;

		case Instruction('R', '+'): //SR : switch range
			if (Current_Channel == 0)
			{
				if (range0 > RANGE_MIN)
				{
					range0--;
				}
			}
			else
			{
				if (range1 > RANGE_MIN)
				{
					range1--;
				}
			}
			Send_Instruction('R', 'e');
			break;
		case Instruction('N', 'M'): //next mode
			if (Current_Channel == 0)
			{
				if (ch0_mode < MODE_OFF)
				{
					ch0_mode++;
				}
				else
				{
					ch0_mode = MODE_ON;
				}
			}
			else
			{
				if (ch1_mode < MODE_OFF)
				{
					ch1_mode++;
				}
				else
				{
					ch1_mode = MODE_ON;
				}
			}
			Send_Instruction('R', 'e');
			break;

		case Instruction('P', 'M'): //previous mode
			if (Current_Channel == 0)
			{
				if (ch0_mode > MODE_ON)
				{
					ch0_mode++;
				}
				else
				{
					ch0_mode = MODE_OFF;
				}
			}
			else
			{
				if (ch1_mode > MODE_ON)
				{
					ch1_mode++;
				}
				else
				{
					ch1_mode = MODE_OFF;
				}
			}
			Send_Instruction('R', 'e');
			break;

		case Instruction('O', '+'): //O+
			if (Current_Channel == 0)
			{
				if (ch0_off < 4095)
				{
					ch0_off += 4096 / VREF[range0];
				}
			}
			else
			{
				if (ch1_off < 4095)
				{
					ch1_off += 4096 / VREF[range1];
				}
			}
			Send_Instruction('R', 'e');
			break;
		case Instruction('O', '-'): //O-
			if (Current_Channel == 0)
			{
				if (ch0_off > -4095)
				{
					ch0_off -= 4096 / VREF[range0];
				}
			}
			else
			{
				if (ch1_off > -4095)
				{
					ch1_off -= 4096 / VREF[range1];
				}
			}
			Send_Instruction('R', 'e');
			break;

		case Instruction('N', 'c'): //next trig channel
			if (trig_ch == 0)
			{
				trig_ch = 1;
			}
			else
			{
				trig_ch = 0;
			}
			Send_Instruction('R', 'e');
			break;
		case Instruction('P', 'c'): // previous trig channel
			if (trig_ch == 0)
			{
				trig_ch = 1;
			}
			else
			{
				trig_ch = 0;
			}
			Send_Instruction('R', 'e');
			break;
		case Instruction('N', 'm'): // next trig mode
			if (trig_mode < TRIG_SCAN)
			{
				trig_mode++;
			}
			else
			{
				trig_mode = TRIG_AUTO;
			}
			Send_Instruction('R', 'e');
			break;
		case Instruction('P', 'm'): // previous trig mode
			if (trig_mode > TRIG_AUTO)
			{
				trig_mode--;
			}
			else
			{
				trig_mode = TRIG_SCAN;
			}
			Send_Instruction('R', 'e');
			break;

		case Instruction('L', '+'): // L+ : Switch trigger level (thresold)
			if (trig_lv < 60)
			{
				trig_lv++;
			}
			Send_Instruction('R', 'e');
			break;

		case Instruction('L', '-'): // L- : Switch trigger level (thresold)
			if (trig_lv > 0)
			{
				trig_lv--;
			}
			Send_Instruction('R', 'e');
			break;

		case Instruction('N', 'E'): // next trigger edge
			if (trig_edge == TRIG_E_UP)
			{
				trig_edge = TRIG_E_DN;
			}
			else
			{
				trig_edge = TRIG_E_UP;
			}
			Send_Instruction('R', 'e');
			break;

		case Instruction('P', 'E'): // next trigger edge
			if (trig_edge == TRIG_E_UP)
			{
				trig_edge = TRIG_E_DN;
			}
			else
			{
				trig_edge = TRIG_E_UP;
			}
			Send_Instruction('R', 'e');
			break;

		case Instruction('r', '+'):
			if (rate < RATE_MAX)
			{
				rate++;
			}
			Send_Instruction('R', 'e');
			break;

		case Instruction('r', '-'):
			if (rate > RATE_MIN)
			{
				rate--;
			}
			Send_Instruction('R', 'e');
			break;
		default:
			break;
		}
	}
}

void Oscilloscope_Class::Refresh_Interface()
{

	memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));

	if (Start)
	{
		Xila.Display.Set_Text(F("STATE_BUT"), F("Stop"));
	}
	else
	{
		Xila.Display.Set_Text(F("STATE_BUT"), F("Start"));
	}
	Xila.Display.Set_Value(F("STATE_BUT"), Start);

	if (Current_Channel == 0)
	{
		Xila.Display.Set_Text(F("CHANNEL_TXT"), F("Channel 0"));
		Xila.Display.Set_Background_Color(F("CHANNEL_TXT"), Xila.Display.Blue);

		strcpy(Temporary_Char_Array, "Range: ");
		strcat(Temporary_Char_Array, Ranges[range0]);
		strcat(Temporary_Char_Array, "/D");
		Xila.Display.Set_Text(F("RANGE_TXT"), Temporary_Char_Array);
		strcpy(Temporary_Char_Array, "Mode: ");
		strcat(Temporary_Char_Array, Modes[ch0_mode]);
		Xila.Display.Set_Text(F("MODE_TXT"), Temporary_Char_Array);
		sprintf(Temporary_Char_Array, "Offset: %i", ch0_off);
		Xila.Display.Set_Text(F("OFFSET_TXT"), Temporary_Char_Array);

		sprintf(Temporary_Char_Array, "Pin: %i", ad_ch0);
		Xila.Display.Set_Text(F("PIN_TXT"), Temporary_Char_Array);
	}
	else
	{
		Xila.Display.Set_Text(F("CHANNEL_TXT"), F("Channel 1"));
		Xila.Display.Set_Background_Color(F("CHANNEL_TXT"), Xila.Display.Yellow);

		strcpy(Temporary_Char_Array, "Range: ");
		strcat(Temporary_Char_Array, Ranges[range1]);
		strcat(Temporary_Char_Array, "/D");
		Xila.Display.Set_Text(F("RANGE_TXT"), Temporary_Char_Array);
		strcpy(Temporary_Char_Array, "Mode: ");
		strcat(Temporary_Char_Array, Modes[ch1_mode]);
		Xila.Display.Set_Text(F("MODE_TXT"), Temporary_Char_Array);
		sprintf(Temporary_Char_Array, "Offset: %i", ch1_off);
		Xila.Display.Set_Text(F("OFFSET_TXT"), Temporary_Char_Array);

		sprintf(Temporary_Char_Array, "Pin: %i", ad_ch1);
		Xila.Display.Set_Text(F("PIN_TXT"), Temporary_Char_Array);
	}

	strcpy(Temporary_Char_Array, "Rate: ");
	strcat(Temporary_Char_Array, Rates[rate]);

	Xila.Display.Set_Text(F("RATE_TXT"), Temporary_Char_Array);

	sprintf(Temporary_Char_Array, "Mode: %s", TRIG_Modes[trig_mode]);
	Xila.Display.Set_Text(F("TMODE_TXT"), Temporary_Char_Array);
	sprintf(Temporary_Char_Array, "Level: %i", trig_lv);
	Xila.Display.Set_Text(F("TLEVEL_TXT"), Temporary_Char_Array);

	if (trig_edge == TRIG_E_DN)
	{
		Xila.Display.Set_Text(F("TEDGE_TXT"), F("Edge: Down"));
	}
	else
	{
		Xila.Display.Set_Text(F("TEDGE_TXT"), F("Edge: Up"));
	}

	sprintf(Temporary_Char_Array, "Channel: %i", trig_ch);
	Xila.Display.Set_Text(F("TCHANNEL_TXT"), Temporary_Char_Array);
}

void Oscilloscope_Class::Refresh_Waveform()
{
	if (Start)
	{
		Xila.Display.Clear_Waveform(Waveform_ID, 0);
		Xila.Display.Clear_Waveform(Waveform_ID, 1);

		if (ch0_mode != MODE_OFF)
		{
			Xila.Display.Add_Value_Waveform(Waveform_ID, 0, data[sample + 0], SAMPLES);
		}
		if (ch1_mode != MODE_OFF)
		{
			Xila.Display.Add_Value_Waveform(Waveform_ID, 1, data[sample + 1], SAMPLES);
		}
	}
}

void Oscilloscope_Class::Trigger()
{
	if (trig_mode != TRIG_SCAN)
	{
		unsigned long st = Xila.Time.Milliseconds();
		short oad = (trig_ch == 0) ? (adRead(ad_ch0, ch0_mode, ch0_off)) : (adRead(ad_ch1, ch1_mode, ch1_off));
		for (;;)
		{
			short ad;
			if (trig_ch == 0)
			{
				ad = adRead(ad_ch0, ch0_mode, ch0_off);
			}
			else
			{
				ad = adRead(ad_ch1, ch1_mode, ch1_off);
			}

			if (trig_edge == TRIG_E_UP)
			{
				if (ad >= trig_lv && ad > oad)
				{
					break;
				}
			}
			else
			{
				if (ad <= trig_lv && ad < oad)
				{
					break;
				}
			}
			oad = ad;

			if (trig_mode == TRIG_SCAN)
			{
				break;
			}
			if (trig_mode == TRIG_AUTO && (Xila.Time.Milliseconds() - st) > 100)
			{
				break;
			}
		}
	}
}

void Oscilloscope_Class::Sampling()
{
	// sample and draw depending on the sampling rate
	if (rate <= 5 && Start)
	{
		(sample == 0) ? (sample = 2) : (sample = 0); // change the index for the double buffer

		if (rate == 0) // full speed, channel 0 only
		{
			for (int i = 0; i < SAMPLES; i++)
			{
				data[sample + 0][i] = adRead(ad_ch0, ch0_mode, ch0_off);
			}
			for (int i = 0; i < SAMPLES; i++)
			{
				data[sample + 1][i] = 0;
			}
		}
		else if (rate == 1) // full speed, channel 1 only
		{
			for (int i = 0; i < SAMPLES; i++)
			{
				data[sample + 1][i] = adRead(ad_ch1, ch1_mode, ch1_off);
			}
			for (int i = 0; i < SAMPLES; i++)
			{
				data[sample + 0][i] = 0;
			}
		}
		else if (rate == 2) // full speed, dual channel
		{
			for (int i = 0; i < SAMPLES; i++)
			{
				data[sample + 0][i] = adRead(ad_ch0, ch0_mode, ch0_off);
				data[sample + 1][i] = adRead(ad_ch1, ch1_mode, ch1_off);
			}
		}
		else if (rate >= 3 && rate <= 5) // .5ms, 1ms or 2ms sampling
		{
			const uint32_t r_[] = {(uint32_t)5000 / Dots_Per_Division,
								   (uint32_t)10000 / Dots_Per_Division,
								   (uint32_t)20000 / Dots_Per_Division};

			unsigned long st = (uint32_t)Xila.Time.Microseconds();
			unsigned long r = r_[rate - 3];
			for (int i = 0; i < SAMPLES; i++)
			{
				while ((st - (uint32_t)Xila.Time.Microseconds()) < r)
				{
					;
				}
				st += r;
				data[sample + 0][i] = adRead(ad_ch0, ch0_mode, ch0_off);
				data[sample + 1][i] = adRead(ad_ch1, ch1_mode, ch1_off);
			}
		}
		Send_Instruction('R', 'W');
	}
	else if (Start)
	{ // 5ms - 500ms sampling
		// copy currently showing data to another
		if (sample == 0)
		{
			for (int i = 0; i < SAMPLES; i++)
			{
				data[2][i] = data[0][i];
				data[3][i] = data[1][i];
			}
		}
		else
		{
			for (int i = 0; i < SAMPLES; i++)
			{
				data[0][i] = data[2][i];
				data[1][i] = data[3][i];
			}
		}

		const uint32_t r_[] = {(uint32_t)50000 / Dots_Per_Division,
							   (uint32_t)100000 / Dots_Per_Division,
							   (uint32_t)200000 / Dots_Per_Division,
							   (uint32_t)500000 / Dots_Per_Division,
							   (uint32_t)1000000 / Dots_Per_Division,
							   (uint32_t)2000000 / Dots_Per_Division,
							   (uint32_t)5000000 / Dots_Per_Division,
							   (uint32_t)10000000 / Dots_Per_Division};

		unsigned long st = (uint32_t)Xila.Time.Microseconds();
		Set_Watchdog_Timeout(30000);	// Add extra watchdog timeout for sampling
		for (int i = 0; i < SAMPLES; i++)
		{
			while ((st - (uint32_t)Xila.Time.Microseconds()) < r_[rate - 6])
			{
				if (rate < 6)
				{
					break;
				}
			}
			if (rate < 6) // sampling rate has been changed
			{
				break;
			}
			st += r_[rate - 6];
			if (st - (uint32_t)Xila.Time.Microseconds() > r_[rate - 6]) // sampling rate has been changed to shorter interval
			{
				st = (uint32_t)Xila.Time.Microseconds();
			}
			if (!Start)
			{
				i--;
				continue;
			}
			data[sample + 0][i] = adRead(ad_ch0, ch0_mode, ch0_off);
			data[sample + 1][i] = adRead(ad_ch1, ch1_mode, ch1_off);
		}
		Set_Watchdog_Timeout();		// Reset watchdog timeout
		Send_Instruction('R', 'W');
	}
}
