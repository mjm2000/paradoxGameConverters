/*Copyright (c) 2016 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/

#include <utility>
#include "CK2World/Opinion/IRepository.h"
#include "gmock/gmock.h"

#ifndef REPOSITORYMOCK_H_
#define REPOSITORYMOCK_H_

namespace ck2
{
namespace opinion
{
namespace mocks
{

class RepositoryMock : public ::ck2::opinion::IRepository
{
    public:
        MOCK_METHOD1(initOpinions, void(IObject*));
        MOCK_METHOD1(getBaseValue, int(std::string));
};

} // namespace mocks
} // namespace opinion
} // namespace repository

#endif // REPOSITORYMOCK_H_
