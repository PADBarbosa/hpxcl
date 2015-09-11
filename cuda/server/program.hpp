// Copyright (c)    2013 Damond Howard
//                  2015 Patrick Diehl
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef HPX_CUDA_SERVER_PROGRAM_HPP_
#define HPX_CUDA_SERVER_PROGRAM_HPP_

#include <hpx/hpx.hpp>

#include <cuda.h>
#include <nvrtc.h>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "cuda/fwd_declarations.hpp"
#include "cuda/kernel.hpp"
#include "cuda/export_definitions.hpp"
#include "cuda/cuda_error_handling.hpp"

namespace hpx
{
    namespace cuda
    {
        namespace server
        {
            class HPX_CUDA_EXPORT program
                : public hpx::components::locking_hook<
                    hpx::components::managed_component_base<program>
                    >
            {
                private:

                boost::shared_ptr<device> parent_device;
                hpx::naming::id_type parent_device_id;
                std::string kernel_source;
                std::string kernel_name;
                nvrtcProgram prog;

                public:
                program();

                program(hpx::naming::id_type device_id, std::string code);

                program(hpx::naming::id_type device_id, hpx::serialization::serialize_buffer<char> binary);

                ~program();

                hpx::cuda::kernel create_kernel(std::string module_name, std::string kernel_name);

                void build(std::vector<std::string> compilerFlags);

                void set_source(std::string source);

                HPX_DEFINE_COMPONENT_ACTION(program, build);
                HPX_DEFINE_COMPONENT_ACTION(program, create_kernel);
                HPX_DEFINE_COMPONENT_ACTION(program, set_source);
            };
        }
    }
}

HPX_REGISTER_ACTION_DECLARATION(
    hpx::cuda::server::program::build_action,
    cuda_program_build_action);
HPX_REGISTER_ACTION_DECLARATION(
    hpx::cuda::server::program::create_kernel_action,
    cuda_program_create_kernel_action);
HPX_REGISTER_ACTION_DECLARATION(
    hpx::cuda::server::program::set_source_action,
    cuda_program_set_source_action);

#endif //PROGRAM_2_HPP
