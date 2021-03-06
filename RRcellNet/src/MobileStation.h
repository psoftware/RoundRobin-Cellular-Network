//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __RRCELLNET_MOBILESTATION_H_
#define __RRCELLNET_MOBILESTATION_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class MobileStation : public cSimpleModule
{
private:
    // RNGs indexes
    const short RNG_CQI_INDEX = 0;

    // CQI random distribution type
    bool isBinomial;
    bool validationCQI;
    int fixedCQI;

    // uniform distribution of CQI value
    const short CQI_UNIFORM_A = 1;
    const short CQI_UNIFORM_B = 15;

    // binomial distribution of CQI value
    unsigned int cqi_binomial_n;
    double cqi_binomial_p;

    int idUser;
    int nFrameSlots;
    simtime_t timeFramePeriod;
    cMessage *beepMS;
    cGate *inData_p;
    cGate *outCQI_p;

    // statistics
    unsigned int totalReceivedBits;
    unsigned int lastSlotReceivedBits;
    unsigned int lastSlotRBcount;

    simsignal_t throughputBits_s;
    simsignal_t slottedThroughputBits_s;
    simsignal_t rbCount_s;
    simsignal_t responseTime_s;
  protected:
    virtual void initialize();
    virtual void finish();
    void sendCQI();
    void handleFrameChunk(cMessage *msg);
    virtual void handleMessage(cMessage *msg);
    ~MobileStation();
};

#endif
