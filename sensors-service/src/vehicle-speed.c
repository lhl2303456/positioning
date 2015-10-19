/**************************************************************************
* Component Name: SensorsService
* Author: Marco Residori <marco.residori@xse.de>
*
* Copyright (C) 2013, XS Embedded GmbH
* 
* License:
* This Source Code Form is subject to the terms of the
* Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
* this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
**************************************************************************/

#include "globals.h"
#include "vehicle-speed.h"
#include "sns-meta-data.h"

VehicleSpeedCallback cbVehicleSpeed = 0;
TVehicleSpeedData gVehicleSpeedData;

bool snsVehicleSpeedInit()
{
    pthread_mutex_lock(&mutexCb);
    cbVehicleSpeed = 0;
    pthread_mutex_unlock(&mutexCb);

    return true;
}

bool snsVehicleSpeedDestroy()
{
    pthread_mutex_lock(&mutexCb);
    cbVehicleSpeed = 0;
    pthread_mutex_unlock(&mutexCb);

    return true;
}

bool snsVehicleSpeedGetVehicleSpeedData(TVehicleSpeedData* vehicleSpeed)
{
    if(!vehicleSpeed)
    {
    	return false;
    }

    pthread_mutex_lock(&mutexData);
    *vehicleSpeed = gVehicleSpeedData;
    pthread_mutex_unlock(&mutexData);

    return true;
}

bool snsVehicleSpeedRegisterCallback(VehicleSpeedCallback callback)
{
    if(!callback)
    {
        return false;
    }

    //printf("snsVehicleSpeedRegisterCallback\n");
    pthread_mutex_lock(&mutexCb);
    if(cbVehicleSpeed != 0) 
    {
        //already registered
        pthread_mutex_unlock(&mutexCb);
        return false;
    }
    cbVehicleSpeed = callback;
    pthread_mutex_unlock(&mutexCb);

    return true;
}

bool snsVehicleSpeedDeregisterCallback(VehicleSpeedCallback callback)
{
    if(!callback)
    {
        return false;
    }

    //printf("snsGyroscopeDeregisterCallback\n");
    pthread_mutex_lock(&mutexCb);
    if(cbVehicleSpeed == callback)
    {
        cbVehicleSpeed = 0;
    }
    pthread_mutex_unlock(&mutexCb);

    return false;
}

bool snsVehicleSpeedGetMetaData(TSensorMetaData *data)
{
    if(!data) 
    {
        return false;
    }
    
    pthread_mutex_lock(&mutexData);
    *data = gSensorsMetaData[2];
    pthread_mutex_unlock(&mutexData);

    return true;
}




