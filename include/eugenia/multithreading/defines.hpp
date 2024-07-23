/*
 * Copyright 2024 Marat Melgizin
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
#ifndef EUGENIA_MULTITHREADING_DEFINES_HPP
#define EUGENIA_MULTITHREADING_DEFINES_HPP

#define EUGENIA_NAMESPACE eugenia
#define MULTITHREADING_NAMESPACE multithreading
#define DETAILS_NAMESPACE details
#define EUGENIA_MULTITHREADING_NAMESPACE EUGENIA_NAMESPACE::MULTITHREADING_NAMESPACE
#define EUGENIA_MULTITHREADING_DETAILS_NAMESPACE EUGENIA_MULTITHREADING_NAMESPACE::DETAILS_NAMESPACE
#define EUGENIA_MULTITHREADING_ALLIAS_NAMESPACE emth

#define EUGENIA_NAMESPACE_BEGIN namespace EUGENIA_NAMESPACE {
#define EUGENIA_NAMESPACE_END }

#define MULTITHREADING_NAMESPACE_BEGIN namespace MULTITHREADING_NAMESPACE {
#define MULTITHREADING_NAMESPACE_END }

#define DETAILS_NAMESPACE_BEGIN namespace DETAILS_NAMESPACE {
#define DETAILS_NAMESPACE_END }

#define EUGENIA_MULTITHREADING_NAMESPACE_BEGIN namespace EUGENIA_MULTITHREADING_NAMESPACE {
#define EUGENIA_MULTITHREADING_NAMESPACE_END }

EUGENIA_MULTITHREADING_NAMESPACE_BEGIN
EUGENIA_MULTITHREADING_NAMESPACE_END

namespace EUGENIA_MULTITHREADING_ALLIAS_NAMESPACE = EUGENIA_MULTITHREADING_NAMESPACE;

#endif // !EUGENIA_MULTITHREADING_DEFINES_HPP
