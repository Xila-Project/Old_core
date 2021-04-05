///
 /// @file Time.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1
 /// @date 29-03-2021
 /// 
 /// @copyright Copyright (c) 2021
 /// 


 inline uint32_t Xila_Class::Time_Class::Milliseconds() const
{
  return (uint32_t)(esp_timer_get_time() / 1000ULL);
}

inline int64_t Xila_Class::Time_Class::Microseconds() const
{
  return esp_timer_get_time();
}