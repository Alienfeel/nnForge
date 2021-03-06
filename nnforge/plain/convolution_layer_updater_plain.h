/*
 *  Copyright 2011-2014 Maxim Milakov
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include "layer_updater_plain.h"

namespace nnforge
{
	namespace plain
	{
		class convolution_layer_updater_plain : public layer_updater_plain
		{
		public:
			convolution_layer_updater_plain();

			virtual ~convolution_layer_updater_plain();

			virtual const boost::uuids::uuid& get_uuid() const;

			virtual void test(
				const_additional_buffer_smart_ptr input_buffer,
				additional_buffer_smart_ptr output_buffer,
				std::vector<additional_buffer_smart_ptr>& additional_buffers,
				plain_running_configuration_const_smart_ptr plain_config,
				const_layer_smart_ptr layer_schema,
				const_layer_data_smart_ptr data,
				const_layer_data_custom_smart_ptr data_custom,
				const layer_configuration_specific& input_configuration_specific,
				const layer_configuration_specific& output_configuration_specific,
				unsigned int updater_count,
				unsigned int offset_input_entry_id) const;

			virtual void backprop(
				additional_buffer_smart_ptr input_errors,
				const_additional_buffer_smart_ptr input_neurons,
				const_additional_buffer_smart_ptr output_errors,
				const_additional_buffer_smart_ptr output_neurons,
				std::vector<additional_buffer_smart_ptr>& additional_buffers,
				plain_running_configuration_const_smart_ptr plain_config,
				const_layer_smart_ptr layer_schema,
				const_layer_data_smart_ptr data,
				const_layer_data_custom_smart_ptr data_custom,
				const layer_configuration_specific& input_configuration_specific,
				const layer_configuration_specific& output_configuration_specific,
				unsigned int updater_count) const;

			virtual void update_weights(
				const_additional_buffer_smart_ptr input_neurons,
				const_additional_buffer_smart_ptr output_errors,
				std::vector<additional_buffer_smart_ptr>& additional_buffers,
				layer_data_smart_ptr gradient,
				const_layer_data_custom_smart_ptr data_custom,
				plain_running_configuration_const_smart_ptr plain_config,
				const_layer_smart_ptr layer_schema,
				const layer_configuration_specific& input_configuration_specific,
				const layer_configuration_specific& output_configuration_specific,
				unsigned int updater_count,
				unsigned int offset_input_entry_id) const;

		protected:
			virtual bool is_in_place_backprop() const;

		private:
			static const int max_dimension_count;
		};
	}
}
