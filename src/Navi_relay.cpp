// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  Navi_relay.cpp
 * @brief ${rtcParam.description}
 *
 */
// </rtc-template>

#include "Navi_relay.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const navi_relay_spec[] =
#else
static const char* navi_relay_spec[] =
#endif
  {
    "implementation_id", "Navi_relay",
    "type_name",         "Navi_relay",
    "description",       "${rtcParam.description}",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Navi_relay::Navi_relay(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_relay_inIn("relay_in", m_relay_in),
    m_relay_outOut("relay_out", m_relay_out)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Navi_relay::~Navi_relay()
{
}



RTC::ReturnCode_t Navi_relay::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("relay_in", m_relay_inIn);
  
  // Set OutPort buffer
  addOutPort("relay_out", m_relay_outOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Navi_relay::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Navi_relay::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Navi_relay::onExecute(RTC::UniqueId /*ec_id*/)
{
  if (m_relay_inIn.isNew())
     {
       m_relay_inIn.read();
       std::cout << "Received: " << m_relay_in.data << std::endl;
        m_relay_out.data = 1;
         std::cout << "subscribe: "<< m_relay_out.data <<std::endl;
        m_relay_outOut.write();
      
     }

  return RTC::RTC_OK;
}





extern "C"
{
 
  void Navi_relayInit(RTC::Manager* manager)
  {
    coil::Properties profile(navi_relay_spec);
    manager->registerFactory(profile,
                             RTC::Create<Navi_relay>,
                             RTC::Delete<Navi_relay>);
  }
  
}
