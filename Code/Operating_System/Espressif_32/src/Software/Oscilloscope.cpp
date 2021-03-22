#include "Software/Oscilloscope.hpp"

Oscilloscope_Class *Oscilloscope_Class::Instance_Pointer = NULL;

Oscilloscope_Class::Oscilloscope_Class() : Software_Class(Oscilloscope_Handle)
{
	Xila.Task_Create(Main_Task, "Oscilloscope", Memory_Chunk(8), NULL, &Task_Handle);
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
	(void)pvParameters;
	while (1)
	{

		Instance_Pointer->Check_Commands();
	}
}

void Oscilloscope_Class::Refresh_Interface()
{
	memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
	if ((millis() - Last_Interface_Refresh) >= 1000)
	{
		if (Current_Channel == 0)
		{
			Xila.Display.Set_Text(F("CHANNEL_TXT"), F("Channel 0"));
			Xila.Display.Set_Background_Color(F("CHANNEL_TXT"), Xila.Blue);

			strcpy(Temporary_Char_Array, "Range: ");
			strcat(Temporary_Char_Array, Ranges[range0]);
			strcat(Temporary_Char_Array, "/D");
			Xila.Display.Set_Text(F("RANGE_TXT"), Temporary_Char_Array);
			strcpy(Temporary_Char_Array, "Mode: ");
			strcat(Temporary_Char_Array, Modes[ch0_mode]);
			Xila.Display.Set_Text(F("MODE_TXT"), Temporary_Char_Array);
			sprintf(Temporary_Char_Array, "Offset: %i", ch0_off);
			Xila.Display.Set_Text(F("OFFSET_TXT"), Temporary_Char_Array);
		}
		else
		{
			Xila.Display.Set_Text(F("CHANNEL_TXT"), F("Channel 1"));
			Xila.Display.Set_Background_Color(F("CHANNEL_TXT"), Xila.Yellow);

			strcpy(Temporary_Char_Array, "Range: ");
			strcat(Temporary_Char_Array, Ranges[range1]);
			strcat(Temporary_Char_Array, "/D");
			Xila.Display.Set_Text(F("RANGE_TXT"), Temporary_Char_Array);
			strcpy(Temporary_Char_Array, "Mode: ");
			strcat(Temporary_Char_Array, Modes[ch1_mode]);
			Xila.Display.Set_Text(F("MODE_TXT"), Temporary_Char_Array);
			sprintf(Temporary_Char_Array, "Offset: %i", ch1_off);
			Xila.Display.Set_Text(F("OFFSET_TXT"), Temporary_Char_Array);
		}

		strcpy(Temporary_Char_Array, "Rate: ");
		strcat(Temporary_Char_Array, Rates[rate]);

		Xila.Display.Set_Text(F("RATE_TXT"), Temporary_Char_Array);

		sprintf(Temporary_Char_Array, "Mode: %i", trig_mode);
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

		Last_Interface_Refresh = millis();
	}
}

void Oscilloscope_Class::Refresh_Waveform()
{
	Xila.Display.Clear_Waveform(Waveform_ID, 0);
	Xila.Display.Clear_Waveform(Waveform_ID, 1);

	if (ch0_mode != MODE_OFF)
	{
		Xila.Display.Add_Value_Waveform(Waveform_ID, 0, (uint8_t *)data[sample + 0], SAMPLES - 1);
	}

	Check_Commands();

	if (ch1_mode != MODE_OFF)
	{
		Xila.Display.Add_Value_Waveform(Waveform_ID, 0, (uint8_t *)data[sample + 1], SAMPLES - 1);
	}

	Check_Commands();
}

long Oscilloscope_Class::adRead(short ch, short mode, int off)
{
	long a = analogRead(ch);
	a = (((a + off) * VREF[(ch == ad_ch0) ? range0 : range1]) / 10000UL) + 30;
	a = ((a >= LCD_HEIGHT) ? LCD_HEIGHT : a);
	if (mode == MODE_INV)
	{
		return LCD_HEIGHT - a;
	}
	return a;
}

/*void Oscilloscope_Class::SigmaDelta_Task(void *pvParameters)
{
	sigmaDeltaSetup(0, 312500);
	sigmaDeltaAttachPin(5, 0);
	sigmaDeltaWrite(0, 0);
	while (1)
	{
		static uint8_t i = 0;
		sigmaDeltaWrite(0, i++);
		delayMicroseconds(50);
	}
	vTaskDelete(NULL);
}*/

/*void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 255)
{
	uint32_t duty = (8191 / valueMax) * min(value, valueMax);
	ledcWrite(channel, duty);
}

// Make a PWM generator task on core 0
// Signal generator pin 2
void LedC_Task(void *parameter)
{
	ledcSetup(0, 50, 13);
	ledcAttachPin(2, 0);

	for (;;)
	{
		ledcAnalogWrite(0, amplitude);
		amplitude = amplitude + amplitudeStep;
		if (amplitude <= 0 || amplitude >= 255)
		{
			amplitudeStep = -amplitudeStep;
		}
		delay(30);
	}
	vTaskDelete(NULL);
}

void Oscilloscope_Class::SigmaDelta_Task(void *parameter)
{
	sigmaDeltaSetup(0, 312500);
	sigmaDeltaAttachPin(5, 0);
	sigmaDeltaWrite(0, 0);
	for (;;)
	{
		static uint8_t i = 0;
		sigmaDeltaWrite(0, i++);
		delayMicroseconds(50);
	}
	vTaskDelete(NULL);
}*/

void Oscilloscope_Class::Run()
{

	if (trig_mode != TRIG_SCAN)
	{
		unsigned long st = millis();
		short oad = (trig_ch == 0) ? (adRead(ad_ch0, ch0_mode, ch0_off)) : (adRead(ad_ch1, ch1_mode, ch1_off));
		for (;;)
		{
			Verbose_Print_Line("Trig scan");
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

			//Check_Commands();

			if (trig_mode == TRIG_SCAN)
			{
				break;
			}
			if (trig_mode == TRIG_AUTO && (millis() - st) > 100)
			{
				break;
			}
		}
	}

	// sample and draw depending on the sampling rate
	if (rate <= 5 && Start)
	{
		Verbose_Print_Line("Sample and draw");
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
			const unsigned long r_[] = {(uint32_t)(5000 / DOTS_DIV), (uint32_t)(10000 / DOTS_DIV), (uint32_t)(20000 / DOTS_DIV)};
			unsigned long st = micros();
			unsigned long r = r_[rate - 3];
			for (int i = 0; i < SAMPLES; i++)
			{
				while ((st - micros()) < r)
				{
					;
				}
				st += r;
				data[sample + 0][i] = adRead(ad_ch0, ch0_mode, ch0_off);
				data[sample + 1][i] = adRead(ad_ch1, ch1_mode, ch1_off);
			}
		}
		Refresh_Waveform();
		//Check_Commands();
		//Refresh_Interface();
	}
	else if (Start)
	{ // 5ms - 500ms sampling
		// copy currently showing data to another
		Verbose_Print_Line("Start sampling");
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

		const unsigned long r_[] = {(uint32_t)(50000 / DOTS_DIV), (uint32_t)(100000 / DOTS_DIV), (uint32_t)(200000 / DOTS_DIV),
									(uint32_t)(500000 / DOTS_DIV), (uint32_t)(1000000 / DOTS_DIV), (uint32_t)(2000000 / DOTS_DIV),
									(uint32_t)(5000000 / DOTS_DIV), (uint32_t)(10000000 / DOTS_DIV)};
		unsigned long st = micros();
		for (int i = 0; i < SAMPLES; i++)
		{
			while ((st - micros()) < r_[rate - 6])
			{
				//Check_Commands();
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
			if (st - micros() > r_[rate - 6]) // sampling rate has been changed to shorter interval
			{
				st = micros();
			}
			if (!Start)
			{
				i--;
				continue;
			}
			data[sample + 0][i] = adRead(ad_ch0, ch0_mode, ch0_off);
			data[sample + 1][i] = adRead(ad_ch1, ch1_mode, ch1_off);
		}
		Refresh_Waveform();
		//Refresh_Interface();
	}
}

void Oscilloscope_Class::Check_Commands()
{
	switch (Get_Instruction())
	{
	case Xila.Idle:
		Xila.Delay(20);
		Refresh_Interface();
		Run();
		break;
	case Xila.Open:
		Xila.Display.Set_Current_Page(F("Oscilloscope"));
		break;
	case Xila.Maximize:
		Xila.Display.Set_Current_Page(F("Oscilloscope"));
		Refresh_Interface();
		break;
	case Xila.Minimize:
		break;
	case Xila.Close:
		delete Instance_Pointer;
		Xila.Task_Delete();
		break;
	case Xila.Watchdog: //reset watchdog
		Xila.Feed_Watchdog();
		break;
	case Instruction('C', 'l'):
		Xila.Software_Close(Oscilloscope_Handle);
		break;
	case Instruction('M', 'i'):
		Xila.Software_Minimize(Oscilloscope_Handle);
		break;
	case Instruction('S', 't'): // SA : Start
		Start = true;
		break;
	case Instruction('s', 't'):
		Start = false;
		break;
	case Instruction('N', 'C'): // next channel
		if (Current_Channel == 0)
		{
			Current_Channel = 1;
			Xila.Display.Set_Text(F("CHANNEL_TXT"), F("Channel 1"));
			Xila.Display.Set_Background_Color(F("CHANNEL_TXT"), Xila.Yellow);
		}
		else
		{
			Current_Channel = 0;
			Xila.Display.Set_Text(F("CHANNEL_TXT"), F("Channel 0"));
			Xila.Display.Set_Background_Color(F("CHANNEL_TXT"), Xila.Blue);
		}
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
		break;
	case Instruction('R', '-'):
		if (Current_Channel == 0)
		{
			if (range0 > RANGE_MIN)
			{
				range0--;
				Xila.Display.Set_Text(F("RANGE_TXT"), "Range: " + String(Ranges[range0]) + "/D");
			}
		}
		else
		{
			if (range1 > RANGE_MIN)
			{
				range1--;
				Xila.Display.Set_Text(F("RANGE_TXT"), "Range: " + String(Ranges[range1]) + "/D");
			}
		}
		break;
	case Instruction('R', '+'): //SR : switch range
		if (Current_Channel == 0)
		{
			if (range0 < RANGE_MAX)
			{
				range0++;
			}
			Xila.Display.Set_Text(F("RANGE_TXT"), "Range: " + String(Ranges[range0]) + "/D");
		}
		else
		{
			if (range1 < RANGE_MAX)
			{
				range1++;
			}

			Xila.Display.Set_Text(F("RANGE_TXT"), "Range: " + String(Ranges[range1]) + "/D");
		}
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
			Xila.Display.Set_Text(F("MODE_TXT"), "Mode: " + String(Modes[ch0_mode]));
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
			Xila.Display.Set_Text(F("MODE_TXT"), "Mode: " + String(Modes[ch1_mode]));
		}
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
			Xila.Display.Set_Text(F("MODE_TXT"), "Mode: " + String(Modes[ch0_mode]));
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
			Xila.Display.Set_Text(F("MODE_TXT"), "Mode: " + String(Modes[ch1_mode]));
		}
		break;

	case Instruction('O', '+'): //O+
		if (Current_Channel == 0)
		{
			if (ch0_off < 4095)
			{
				ch0_off += 4096 / VREF[range0];
			}
			Xila.Display.Set_Text(F("OFFSET_TXT"), "Offset: " + String(ch0_off));
		}
		else
		{
			if (ch1_off < 4095)
			{
				ch1_off += 4096 / VREF[range1];
			}
			Xila.Display.Set_Text(F("OFFSET_TXT"), "Offset: " + String(ch1_off));
		}
		break;
	case Instruction('O', '-'): //O-
		if (Current_Channel == 0)
		{
			if (ch0_off > -4095)
			{
				ch0_off -= 4096 / VREF[range0];
			}
			Xila.Display.Set_Text(F("OFFSET_TXT"), "Offset: " + String(ch0_off));
		}
		else
		{
			if (ch1_off > -4095)
			{
				ch1_off -= 4096 / VREF[range1];
			}
			Xila.Display.Set_Text(F("OFFSET_TXT"), "Offset: " + String(ch1_off));
		}
		break;

	case Instruction('N', 'c'): //next trig channel
		if (trig_ch == 0)
		{
			trig_ch = 1;
			Xila.Display.Set_Text(F("TCHANNEL_TXT"), F("Channel: 1"));
		}
		else
		{
			trig_ch = 0;
			Xila.Display.Set_Text(F("TCHANNEL_TXT"), F("Channel: 0"));
		}
		break;
	case Instruction('P', 'c'): // previous trig channel
		if (trig_ch == 0)
		{
			trig_ch = 1;
			Xila.Display.Set_Text(F("TCHANNEL_TXT"), F("Channel: 1"));
		}
		else
		{
			trig_ch = 0;
			Xila.Display.Set_Text(F("TCHANNEL_TXT"), F("Channel: 0"));
		}
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
		Xila.Display.Set_Text(F("TMODE_TXT"), "Mode: " + String(TRIG_Modes[trig_mode]));
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
		Xila.Display.Set_Text(F("TMODE_TXT"), "Mode: " + String(TRIG_Modes[trig_mode]));
		break;

	case Instruction('L', '+'): // L+ : Switch trigger level (thresold)
		if (trig_lv < 60)
		{
			trig_lv++;
		}
		Xila.Display.Set_Text(F("TLEVEL_TXT"), "Level: " + String(trig_lv));
		break;

	case Instruction('L', '-'): // L- : Switch trigger level (thresold)
		if (trig_lv > 0)
		{
			trig_lv--;
		}
		Xila.Display.Set_Text(F("TLEVEL_TXT"), "Level: " + String(trig_lv));
		break;

	case Instruction('N', 'E'): // next trigger edge
		if (trig_edge == TRIG_E_UP)
		{
			trig_edge = TRIG_E_DN;
			Xila.Display.Set_Text(F("TEDGE_TXT"), F("Edge: Up"));
		}
		else
		{
			trig_edge = TRIG_E_UP;
			Xila.Display.Set_Text(F("TEDGE_TXT"), F("Edge: Down"));
		}

		break;

	case Instruction('P', 'E'): // next trigger edge
		if (trig_edge == TRIG_E_UP)
		{
			trig_edge = TRIG_E_DN;
			Xila.Display.Set_Text(F("TEDGE_TXT"), F("Edge: Up"));
		}
		else
		{
			trig_edge = TRIG_E_UP;
			Xila.Display.Set_Text(F("TEDGE_TXT"), F("Edge: Down"));
		}
		break;

	case Instruction('r', '+'):
		if (rate < RATE_MAX)
		{
			rate++;
		}
		Xila.Display.Set_Text(F("TRATE_TXT"), "Rate: " + String(Rates[rate]) + "/Div");
		break;

	case Instruction('r', '-'):
		if (rate > RATE_MIN)
		{
			rate--;
		}
		Xila.Display.Set_Text(F("TRATE_TXT"), "Rate: " + String(Rates[rate]) + "/Div");
		break;

	default:
		break;
	}
}