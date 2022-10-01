classdef MatlabException<uint8&MATLAB.IEnumerableException
    enumeration
        Success(0)
        Input_is_not_a_string(1)
        File_operation_failed(2)
        Zip_failed_to_open(3)
        Zip_filename_search_failed(4)
        Zip_file_failed_to_open(5)
        Wrong_input_parameter_type(6)
        Zip_file_read_failed(7)
        Wrong_number_of_input_parameters(8)
        Zip_archive_is_invalid(9)
        Failed_to_get_Zip_file_name(10)
		Failed_to_get_the_stat_of_the_Zip_file(11)
		Zip_doesnt_log_file_size(12)
		Unable_to_uniform_size(13)

        Missing_matching_key(251)
        Fields_not_found_in_tables(252)
		Error_copying_file(253)
		Error_deleting_file(254)
		Error_moving_file(255)
	end
end