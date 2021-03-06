/*Copyright (c) 2018 The Paradox Game Converters Project

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



#ifndef PROVINCE_DEFINITIONS
#define PROVINCE_DEFINITIONS



#include <optional>
#include <map>
#include <set>
#include "../Color.h"
using namespace std;



class provinceDefinitions
{
	public:
		static const set<int>& getLandProvinces()
		{
			return getInstance()->landProvinces;
		}
		static const bool isLandProvince(int province)
		{
			return (getInstance()->landProvinces.count(province) > 0);
		}
		static const bool isSeaProvince(int province)
		{
			return (getInstance()->seaProvinces.count(province) > 0);
		}

		static optional<int> getProvinceFromColor(const ConverterColor::Color& color)
		{
			return getInstance()->GetProvinceFromColor(color);
		}

	private:
		static provinceDefinitions* instance;
		static provinceDefinitions* getInstance()
		{
			if (instance == nullptr)
			{
				instance = new provinceDefinitions();
			}

			return instance;
		}
		provinceDefinitions() noexcept;

		provinceDefinitions(const provinceDefinitions&) = delete;
		provinceDefinitions& operator=(const provinceDefinitions&) = delete;

		optional<int> GetProvinceFromColor(const ConverterColor::Color& color) const;

		int getIntFromColor(const ConverterColor::Color& color) const;

		set<int> landProvinces;
		set<int> seaProvinces;
		map<int, int> colorToProvinceMap;	// colors are a packed integer to work around some issues. If you can get Colors to work directly, please replace this hack.
};




#endif // PROVINCE_DEFINITIONS