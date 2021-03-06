// ======================================================================
// \title  RateGroupDriver/test/ut/TesterBase.hpp
// \author Auto-generated
// \brief  hpp file for RateGroupDriver component test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef RateGroupDriver_TESTER_BASE_HPP
#define RateGroupDriver_TESTER_BASE_HPP

#include <Svc/RateGroupDriver/RateGroupDriverComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <stdio.h>
#include <Fw/Port/InputSerializePort.hpp>

namespace Svc {

  //! \class RateGroupDriverTesterBase
  //! \brief Auto-generated base class for RateGroupDriver component test harness
  //!
  class RateGroupDriverTesterBase :
    public Fw::PassiveComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Initialization
      // ----------------------------------------------------------------------

      //! Initialize object RateGroupDriverTesterBase
      //!
      virtual void init(
          const NATIVE_INT_TYPE instance = 0 //!< The instance number
      );

    public:

      // ----------------------------------------------------------------------
      // Connectors for 'to' ports
      // Connect these output ports to the input ports under test
      // ----------------------------------------------------------------------

      //! Connect CycleIn to to_CycleIn[portNum]
      //!
      void connect_to_CycleIn(
          const NATIVE_INT_TYPE portNum, //!< The port number
          Svc::InputCyclePort *const CycleIn //!< The port
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for 'from' ports
      // Connect these input ports to the output ports under test
      // ----------------------------------------------------------------------

      //! Get the port that receives input from CycleOut
      //!
      //! \return from_CycleOut[portNum]
      //!
      Svc::InputCyclePort* get_from_CycleOut(
          const NATIVE_INT_TYPE portNum //!< The port number
      );

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object RateGroupDriverTesterBase
      //!
      RateGroupDriverTesterBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, //!< The component name
          const U32 maxHistorySize //!< The maximum size of each history
#else
          const U32 maxHistorySize //!< The maximum size of each history
#endif
      );

      //! Destroy object RateGroupDriverTesterBase
      //!
      virtual ~RateGroupDriverTesterBase(void);

      // ----------------------------------------------------------------------
      // Test history
      // ----------------------------------------------------------------------

    protected:

      //! \class History
      //! \brief A history of port inputs
      //!
      template <typename T> class History {

        public:

          //! Create a History
          //!
          History(
              const U32 maxSize //!< The maximum history size
          ) : 
              numEntries(0), 
              maxSize(maxSize) 
          { 
            this->entries = new T[maxSize];
          }

          //! Destroy a History
          //!
          ~History() {
            delete[] this->entries;
          }

          //! Clear the history
          //!
          void clear() { this->numEntries = 0; }

          //! Push an item onto the history
          //!
          void push_back(
              T entry //!< The item
          ) {
            FW_ASSERT(this->numEntries < this->maxSize);
            entries[this->numEntries++] = entry;
          }

          //! Get an item at an index
          //!
          //! \return The item at index i
          //!
          T at(
              const U32 i //!< The index
          ) const {
            FW_ASSERT(i < this->numEntries);
            return entries[i];
          }

          //! Get the number of entries in the history
          //!
          //! \return The number of entries in the history
          //!
          U32 size(void) const { return this->numEntries; }

        private:

          //! The number of entries in the history
          //!
          U32 numEntries;

          //! The maximum history size
          //!
          const U32 maxSize;

          //! The entries
          //!
          T *entries;

      };

      //! Clear all history
      //!
      void clearHistory(void);

    protected:

      // ----------------------------------------------------------------------
      // Handler prototypes for typed from ports
      // ----------------------------------------------------------------------

      //! Handler prototype for from_CycleOut
      //!
      virtual void from_CycleOut_handler(
          const NATIVE_INT_TYPE portNum, //!< The port number
          Svc::TimerVal &cycleStart //!< Cycle start timer value
      ) = 0;

      //! Handler base function for from_CycleOut
      //!
      void from_CycleOut_handlerBase(
          const NATIVE_INT_TYPE portNum, //!< The port number
          Svc::TimerVal &cycleStart //!< Cycle start timer value
      );

    protected:

      // ----------------------------------------------------------------------
      // Histories for typed from ports
      // ----------------------------------------------------------------------

      //! Clear from port history
      //!
      void clearFromPortHistory(void);

      //! The total number of from port entries
      //!
      U32 fromPortHistorySize;

      //! Push an entry on the history for from_CycleOut
      void pushFromPortEntry_CycleOut(
          Svc::TimerVal &cycleStart //!< Cycle start timer value
      );

      //! A history entry for from_CycleOut
      //!
      typedef struct {
        Svc::TimerVal cycleStart;
      } FromPortEntry_CycleOut;

      //! The history for from_CycleOut
      //!
      History<FromPortEntry_CycleOut> 
        *fromPortHistory_CycleOut;

    protected:

      // ----------------------------------------------------------------------
      // Invocation functions for to ports
      // ----------------------------------------------------------------------

      //! Invoke the to port connected to CycleIn
      //!
      void invoke_to_CycleIn(
          const NATIVE_INT_TYPE portNum, //!< The port number
          Svc::TimerVal &cycleStart //!< Cycle start timer value
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for port counts
      // ----------------------------------------------------------------------

      //! Get the number of to_CycleIn ports
      //!
      //! \return The number of to_CycleIn ports
      //!
      NATIVE_INT_TYPE getNum_to_CycleIn(void) const;

      //! Get the number of from_CycleOut ports
      //!
      //! \return The number of from_CycleOut ports
      //!
      NATIVE_INT_TYPE getNum_from_CycleOut(void) const;

    protected:

      // ----------------------------------------------------------------------
      // Connection status for to ports
      // ----------------------------------------------------------------------

      //! Check whether port is connected
      //!
      //! Whether to_CycleIn[portNum] is connected
      //!
      bool isConnected_to_CycleIn(
          const NATIVE_INT_TYPE portNum //!< The port number
      );

    private:

      // ----------------------------------------------------------------------
      // To ports
      // ----------------------------------------------------------------------

      //! To port connected to CycleIn
      //!
      Svc::OutputCyclePort m_to_CycleIn[1];

    private:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      //! From port connected to CycleOut
      //!
      Svc::InputCyclePort m_from_CycleOut[3];

    private:

      // ----------------------------------------------------------------------
      // Static functions for output ports
      // ----------------------------------------------------------------------

      //! Static function for port from_CycleOut
      //!
      static void from_CycleOut_static(
          Fw::PassiveComponentBase *const callComp, //!< The component instance
          const NATIVE_INT_TYPE portNum, //!< The port number
          Svc::TimerVal &cycleStart //!< Cycle start timer value
      );

  };

} // end namespace Svc

#endif
