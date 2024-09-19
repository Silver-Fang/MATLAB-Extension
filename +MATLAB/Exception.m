classdef Exception<MATLAB.Lang.IEnumerableException
	enumeration
		Failed_to_split_out_enough_fields
		Unexpected_patch_number
		Lack_of_high_dimensional_index
		Cannot_operate_on_NDTables_with_different_Dimensions
		Index_name_not_found
		NDTable_does_not_contain_these_IndexNames
		Parameter_parsing_failure
		Input_not_tabular
		Container_must_specify_PropertyName_or_MethodName
		Static_argument_not_supported_for_the_specified_type
		Owner_not_modifiable
		Optional_value_not_set
		Impossible_MaxConsecutiveRepeats
		Cannot_change_type_of_Referable_value
		Size_not_compatible_with_array
		Invalid_Alignment
		Empty_inputs_may_return_unexpected_types
		Query_graph_contains_cycles
		Selected_tables_not_sharing_key_columns
		Two_columns_not_connected
		Dot_reference_is_unsupported
		Specified_name_was_not_found
		Example_exception
		NumWantNew_is_too_big
		Range_is_not_a_numerical_type
		Invalid_RestartDisposition
		PathManager_not_installed
		Number_of_EdgeColors_does_not_match_number_of_lines
		Number_of_LineStyles_does_not_match_number_of_lines
		Cannot_own_a_non_handle_value
		Stack_is_empty
		Queue_is_empty
		Empty_vector_must_specify_a_padding_value
		Vector_is_empty
		Index_exceeds_vector_size
		Missing_matching_key
		Column_not_found_in_tables
		Error_copying_file
		Error_deleting_file
		Error_moving_file
		WindowsAPI_cannot_reshape
		WindowsAPI_cannot_vertcat
		WindowsAPI_cannot_end
		WindowsAPI_cannot_horzcat
		Table_or_column_not_found
		UpdateTable_lacks_primary_column
		UpdateTable_column_names_contain_backquotes
		Table_not_found_or_primary_key_missing
		Datetime_TimeZone_not_set
		Unsupported_VariableType
		Dataset_cannot_addprop
		Columns_not_found
		Unexpected_distance
		Invalid_column_name
		Invalid_Operation
	end
end