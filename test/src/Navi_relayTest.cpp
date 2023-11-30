// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  Navi_relayTest.cpp
 * @brief ${rtcParam.description} (test code)
 *
 */
// </rtc-template>

#include "Navi_relayTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const navi_relay_spec[] =
#else
static const char* navi_relay_spec[] =
#endif
  {
    "implementation_id", "Navi_relayTest",
    "type_name",         "Navi_relayTest",
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
Navi_relayTest::Navi_relayTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_relay_inOut("relay_in", m_relay_in),
    m_relay_outIn("relay_out", m_relay_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Navi_relayTest::~Navi_relayTest()
{
}



RTC::ReturnCode_t Navi_relayTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("relay_out", m_relay_outIn);
  
  // Set OutPort buffer
  addOutPort("relay_in", m_relay_inOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Navi_relayTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t Navi_relayTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_relayTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t Navi_relayTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Navi_relayTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Navi_relayTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t Navi_relayTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_relayTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_relayTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_relayTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_relayTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool Navi_relayTest::runTest()
{
    return true;
}


extern "C"
{
 
  void Navi_relayTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(navi_relay_spec);
    manager->registerFactory(profile,
                             RTC::Create<Navi_relayTest>,
                             RTC::Delete<Navi_relayTest>);
  }
  
}
