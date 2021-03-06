/**
The MIT License (MIT)

Copyright (c) 2016 Flavio Moreira

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/**
  * singleton routes commands to subscribers.
  * the addresses for the commands are defined by their subscription key
  */

#ifndef CORE_COMMAND_DISPATCHER_HPP
#define CORE_COMMAND_DISPATCHER_HPP

#include "core/command_interface.hpp"

namespace Hydrogine
{

class CommandDispatcher
{
public:
  ~CommandDispatcher();

  CLASS_METHOD CommandDispatcher* instance();

  ErrorCode subscribe(CommandType type, ICommandee* cmd);
  ErrorCode unSubscribe(const CommandType type, const ICommandee* cmd);
  void dispatch(const CommandMsg& msg);

protected:
  CommandDispatcher(CommandDispatcher&) = delete;
  CommandDispatcher operator=(CommandDispatcher&) = delete;
  CommandDispatcher();
  GLOBAL HashMultiMap< CommandType, ICommandee* > subscribers;
};

} // end namespace Hydrogine

#endif // CORE_COMMAND_DISPATCHER_HPP
