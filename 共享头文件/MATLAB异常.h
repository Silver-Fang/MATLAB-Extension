#pragma once
namespace MATLAB
{
	//和MATLAB端的异常类型保持一致
	enum class Exception
	{
		Successful,
		The_input_is_not_a_string,
		File_operation_failed,
		Zip_failed_to_open,
		Zip_file_name_search_failed,
		Failed_to_open_the_Zip_file,
		Input_parameter_type_is_incorrect,
		Failed_to_read_the_Zip_file,
		The_number_of_entered_parameters_is_incorrect,
		The_Zip_file_is_invalid,
		Failed_to_obtain_the_Zip_file_name,
		Failed_to_obtain_the_Zip_file_details,
		Zip_does_not_record_file_size,
		File_creation_failed,
		Failed_to_get_file_size,
		Failed_to_read_the_file,
		Failed_to_set_end_of_file,
		Failed_to_set_the_file_pointer,
		Failed_to_write_out_the_file,
		Failed_to_close_the_file,
		Failed_to_create_a_file_mapping,
		Failed_to_map_the_file_view,
		Memory_copy_failed,
		Unsupported_read_types,
		Unsupported_write_type,
		Unsupported_array_types,
		Mex_anomaly,
		Fill_data_out_of_memory_range,
		Failed_to_open_file_mapping,
		Specified_device_not_found,
		Incorrect_fill_color_data_type,
		Invalid_pointer,
		Unknown_exception,
		Failed_to_save_the_shortcut,
		Failed_to_open_the_file,
		Failed_to_obtain_metadata,
		Failed_to_decode_pixel_values,
		The_privilege_server_fails_to_start,
		Privilege_server_connection_failed,
		User_denied_access,
		Builtin_bug_fix_command_is_0,
		COM_number_not_found,
		File_not_found,
		Bad_pathname,
		Attempt_to_snatch_the_serialport_occupied_by_yourself,
		Current_MATLAB_version_not_supported,
		Unexpected_error_in_DuplicateHandle,
		Unexpected_error_in_OpenProcess,
		Failed_to_communicate_with_the_privilege_server,
	};
}