/* -*-c++-*- OpenThreads library, Copyright (C) 2002 - 2007  The Open Thread Group
 *
 * This library is open source and may be redistributed and/or modified under
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * OpenSceneGraph Public License for more details.
*/


//
// Mutex - C++ mutex class
// ~~~~~
//

#ifndef _OPENTHREADS_MUTEX_
#define _OPENTHREADS_MUTEX_

#include <OpenThreads/Exports.h>

namespace OpenThreads {

/**
 *  @class Mutex
 *  @brief  This class provides an object-oriented thread mutex interface.
 */
class OPENTHREAD_EXPORT_DIRECTIVE Mutex {

    friend class Condition;

public:

    enum MutexType
    {
        MUTEX_NORMAL,
        MUTEX_RECURSIVE
    };

    /**
     *  Constructor
     */
    Mutex(MutexType type=MUTEX_NORMAL);

    /**
     *  Destructor
     */
    virtual ~Mutex();


    MutexType getMutexType() const { return _mutexType; }


    /**
     *  Lock the mutex
     *
     *  @return 0 if normal, -1 if errno set, errno code otherwise.
     */
    virtual int lock();

    /**
     *  Unlock the mutex
     *
     *  @return 0 if normal, -1 if errno set, errno code otherwise.
     */
    virtual int unlock();

    /**
     *  Test if mutex can be locked.
     *
     *  @return 0 if normal, -1 if errno set, errno code otherwise.
     */
    virtual int trylock();

private:

    /**
     *  Private copy constructor, to prevent tampering.
     */
    Mutex(const Mutex &/*m*/) {};

    /**
     *  Private copy assignment, to prevent tampering.
     */
    Mutex &operator=(const Mutex &/*m*/) {return *(this);};

    /**
     *  Implementation-specific private data.
     */
    void *_prvData;
    MutexType _mutexType;

};

}

#endif // _OPENTHREADS_MUTEX_
