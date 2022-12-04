/***********************************************************************************
 * LearnDirectX11 Project                                                          *
 * @file input.cpp                                                                 *
 * @date 12/3/2022                                                                 *
 * @author Chirs Cheng                                                             *
 * @copyright Copyright (c) 2022 Chris Cheng                                       *
 ***********************************************************************************
 * Permission is hereby granted, free of charge, to any person obtaining a copy    *
 * of this software and associated documentation files (the "Software"), to deal   *
 * in the Software without restriction, including without limitation the rights    *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is           *
 * furnished to do so, subject to the following conditions:                        *
 *                                                                                 *
 * The above copyright notice and this permission notice shall be included in all  *
 * copies or substantial portions of the Software.                                 *
 *                                                                                 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
 * SOFTWARE.                                                                       *
 ***********************************************************************************/
#include "input.h"

InputClass::InputClass(){}
InputClass::InputClass(const InputClass& other){}
InputClass::~InputClass(){}

void InputClass::Initialize()
{
	int i;
	for(i=0; i<256; i++)
		m_keys[i] = false;
	}
}


void InputClass::KeyDown(unsigned int input){
	m_keys[input] = true;
}


void InputClass::KeyUp(unsigned int input){
	m_keys[input] = false;
}

bool InputClass::IsKeyDown(unsigned int key){
	return m_keys[key];
}