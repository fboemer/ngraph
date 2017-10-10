// ----------------------------------------------------------------------------
// Copyright 2017 Nervana Systems Inc.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// ----------------------------------------------------------------------------

#include "ngraph/pass/collect_functions.hpp"
#include "ngraph/function.hpp"
#include "ngraph/log.hpp"
#include "ngraph/node.hpp"
#include "ngraph/ops/function_call.hpp"
#include "ngraph/ops/op.hpp"
#include "ngraph/util.hpp"

using namespace std;
using namespace ngraph;
using namespace ngraph::pass;

bool CollectFunctions::run_on_function(ngraph::Function* func)
{
    set<Function*> functions;
    deque<Function*> stack;
    stack.push_back(func);

    while (stack.empty() == false)
    {
        Function* f = stack.front();
        stack.pop_front();
        functions.insert(f);
        traverse_nodes(f->get_result(), [&](Node* node) {
            op::FunctionCall* fc = dynamic_cast<op::FunctionCall*>(node);
            if (fc)
            {
                stack.push_back(fc->get_function().get());
            }
        });
    }

    get_state().set_functions(functions);

    return false;
}