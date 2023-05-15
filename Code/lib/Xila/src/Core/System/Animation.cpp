/// @file Animation.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 04-03-2023
///
/// @copyright Copyright (c) 2023

#include "Core/System/System.hpp"
#include "Core/Graphics/Graphics.hpp"
#include "Core/Log/Log.hpp"
#include "Core/Sound/Sound.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Methods

void System_Class::Start_Load_Animation(Object_Type *Logo, Graphics_Types::Animation_Type *Animation)
{

  Object_Type Background;

  Background.Create(Object_Type(lv_scr_act()));
  Background.Set_Size(Percentage(100), Percentage(100));
  Background.Set_Style_Background_Color(Color_Type::Black, 0);
  Background.Set_Style_Pad_All(0, 0);

  Logo->Create(Background);
  Logo->Set_Size(256, 256);
  Logo->Set_Alignment(Alignment_Type::Center);
  Logo->Set_Style_Pad_All(0, 0);
  Logo->Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);

  {
    Object_Type Red;
    Red.Create(*Logo);
    Red.Set_Size(40, 84);
    Red.Set_Alignment(Alignment_Type::Top_Left, 64, 64);
    Red.Set_Style_Background_Color(Color_Type::White, 0);
    Red.Set_Style_Shadow_Color(Color_Type::White, 0);
    Red.Set_Style_Opacity(Opacity_Type::Transparent, 0);
  }

  {
    Object_Type Blue;
    Blue.Create(*Logo);
    Blue.Set_Size(84, 40);
    Blue.Set_Alignment(Alignment_Type::Bottom_Left, 64, -64);
    Blue.Set_Style_Background_Color(Color_Type::White, 0);
    Blue.Set_Style_Shadow_Color(Color_Type::White, 0);
    Blue.Set_Style_Opacity(Opacity_Type::Transparent, 0);
  }

  {
    Object_Type Green;
    Green.Create(*Logo);
    Green.Set_Size(40, 84);
    Green.Set_Alignment(Alignment_Type::Bottom_Right, -64, -64);
    Green.Set_Style_Background_Color(Color_Type::White, 0);
    Green.Set_Style_Shadow_Color(Color_Type::White, 0);
    Green.Set_Style_Opacity(Opacity_Type::Transparent, 0);
  }

  {
    Object_Type Yellow;
    Yellow.Create(*Logo);
    Yellow.Set_Size(84, 40);
    Yellow.Set_Alignment(Alignment_Type::Top_Right, -64, 64);
    Yellow.Set_Style_Background_Color(Color_Type::White, 0);
    Yellow.Set_Style_Shadow_Color(Color_Type::White, 0);
    Yellow.Set_Style_Opacity(Opacity_Type::Transparent, 0);
  }

  Animation->Set_Variable(Logo);
  Animation->Set_Values(64, 255);
  Animation->Set_Time(500);
  Animation->Set_Playback_Delay(0);
  Animation->Set_Playback_Time(500);
  Animation->Set_Repeat_Delay(0);
  Animation->Set_Repeat_Count(LV_ANIM_REPEAT_INFINITE); // TODO : Define a constant for this
  Animation->Set_Path_Callback(Graphics_Types::Animation_Type::Path_Ease_In_Out);
  Animation->Set_Execution_Callback(Load_Animation_Callback);
  Animation->Start();
}

void System_Class::Stop_Load_Animation(Object_Type *Logo, Graphics_Types::Animation_Type *Animation)
{
  // - Play startup sound
  Drive_Types::File_Type Startup_Sound = Drive.Open("/Xila/Sounds/Startup.wav");

  Sound_Types::WAV_Decoder_Type WAV_Decoder;
  Sound_Types::File_Player_Type File_Player(Sound.Volume_Stream, Startup_Sound, WAV_Decoder);

  File_Player.Begin();

 File_Player.Loop();

 while (File_Player.Loop() != 0)
 {
   Task.Delay(1);
 }

  if (Animation != NULL)
  {
    delete Animation;
  }

  if (Logo != NULL)
  {
    Logo->Delete();
  }
}

void System_Class::Load_Animation_Callback(void *Object, int32_t Value)
{
  static uint8_t Animated_Part = 2;

  // Log_Verbose("System", "Load animation callback from : %s", Task_Type(xTaskGetCurrentTaskHandle()).Get_Name());

  if ((Value == 255) || (Value == 64))
  {
    if ((Animated_Part == 4))
    {
      if (Value == 64)
      {
        Animated_Part = 1;
      }
    }
    else
    {
      Animated_Part++;
    }
  }

  Object_Type Next_Part = static_cast<Object_Type *>(Object)->Get_Child(Animated_Part - 1);

  // Next_Part.Set_Style_Shadow_Width(255 + 64 - (Coordinate_Type)Value, 0);

  // Task_Type::Delay_Static(1000);

  // Next_Part.Set_Style_Opacity(uint8_t(255 + 64 - Value), 0);

  if ((Animated_Part % 2) == 0)
  {
    // Next_Part.Set_Style_Shadow_Width(255 + 64 - (Coordinate_Type)Value, 0);
    Next_Part.Set_Style_Opacity(uint8_t(255 + 64 - Value), 0);

    Object_Type Previous_Part = static_cast<Object_Type *>(Object)->Get_Child(Animated_Part - 2);

    // Previous_Part.Set_Style_Shadow_Width((Coordinate_Type)Value, 0);
    Previous_Part.Set_Style_Opacity((uint8_t)Value, 0);
  }
  else
  {
    // Next_Part.Set_Style_Shadow_Width(Value, 0);
    Next_Part.Set_Style_Opacity(Value, 0);

    if (Animated_Part == 1)
    {
      Object_Type Previous_Part = static_cast<Object_Type *>(Object)->Get_Child(3);

      // Previous_Part.Set_Style_Shadow_Width(255 + 64 - Value, 0);
      Previous_Part.Set_Style_Opacity(uint8_t(255 + 64 - Value), 0);
    }
    else
    {
      Object_Type Previous_Part = static_cast<Object_Type *>(Object)->Get_Child(Animated_Part - 2);

      // Previous_Part.Set_Style_Shadow_Width(255 + 64 - Value, 0);
      Previous_Part.Set_Style_Opacity(uint8_t(255 + 64 - Value), 0);
    }
  }
}