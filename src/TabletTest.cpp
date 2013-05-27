// -*- C++ -*-
/*!
 * @file  TabletTest.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "TabletTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* tablettest_spec[] =
  {
    "implementation_id", "TabletTest",
    "type_name",         "TabletTest",
    "description",       "ModuleDescription",
    "version",           "0.0.1",
    "vendor",            "ogata-lab",
    "category",          "OutputTabDat",
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
TabletTest::TabletTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_positionIn("position", m_position),
    m_pressureIn("pressure", m_pressure),
    m_orientationIn("orientation", m_orientation),
    m_sizeIn("size", m_size),
    m_outputTabDataOut("outputTabData", m_outputTabData)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
TabletTest::~TabletTest()
{
}



RTC::ReturnCode_t TabletTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("position", m_positionIn);
  addInPort("pressure", m_pressureIn);
  addInPort("orientation", m_orientationIn);
  addInPort("size", m_sizeIn);
  
  // Set OutPort buffer
  addOutPort("outputTabData", m_outputTabDataOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t TabletTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TabletTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TabletTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TabletTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TabletTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t TabletTest::onExecute(RTC::UniqueId ec_id)
{
	if(m_positionIn.isNew()){
		m_positionIn.read();
		std::cout << "position is: " << m_position.data.x << ", " << m_position.data.y << std::endl;
	}
	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t TabletTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TabletTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TabletTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TabletTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TabletTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void TabletTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(tablettest_spec);
    manager->registerFactory(profile,
                             RTC::Create<TabletTest>,
                             RTC::Delete<TabletTest>);
  }
  
};


