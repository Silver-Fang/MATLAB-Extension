classdef WindowsAPI<uint8
	enumeration
		CopyFile(0)
		Delete(1)
		MoveFile(2)	
		ZipOpen(3)
		ZipNameLocate(4)
		ZipFopen(5)
		ZipFread(6)
		ZipFclose(7)
		ZipDiscard(8)
		ZipGetSize(9)
		ZipGetName(10)
		ZipGetNumEntries(11)
		File_Create(12)
		File_GetSize(13)
		File_Read(14)
		File_SetEnd(15)
		File_SetPointer(16)
		File_Write(17)
		File_Close(18)
		MemoryMapping_Create(19)
		MemoryMapping_Open(20)
		MemoryMapping_View(21)
		MemoryMapping_Unview(22)
		MemoryMapping_Close(23)
		Pointer_Allocate(24)
		Pointer_Read(25)
		Pointer_Write(26)
		Pointer_Copy(27)
		Pointer_Release(28)
		TypeCast(29)
		Window_Create(30)
		Window_Destroy(31)
		Window_Image(32)
		Window_Screens(33)
		Window_Clear(34)
		Window_Fill(35)
		Window_RemoveVisual(36)
		LnkShortcut(37)
	end
	methods
		function varargout=Call(obj,varargin)
			import MATLAB.internal.InnerException
			import MATLAB.Lang.*
			varargout=cell(1,nargout);
			[Error,varargout{:}]=WindowsCall(uint8(obj),varargin{:});
			ExceptionType=MatlabException(Error.ExceptionType);
			if ExceptionType~=MatlabException.Success
				switch InnerException(Error.InnerException)
					case InnerException.None
						ExceptionType.Throw;
					case InnerException.Win32Exception
						Detail.InnerException=WindowsErrorCode(typecast(Error.ErrorCode,'uint32'));
					case InnerException.LibzipException
						Detail.InnerException=MATLAB.IO.LibzipException(Error.ErrorCode);
					case InnerException.MexException
						Detail.InnerException=MexException(Error.ErrorCode);
					case InnerException.ComException
						ErrorCode=typecast(Error.ErrorCode,'uint32');
						try
							ErrorCode=WindowsErrorCode(ErrorCode);
						catch ME
							if ME.identifier=="MATLAB:class:InvalidEnum"
								ErrorCode=WindowsErrorCode(bitand(ErrorCode,0x0000ffff));
							else
								ME.rethrow;
							end
						end
						Detail.InnerException=ErrorCode;
				end
				if Error.Index
					Detail.Index=Error.Index;
					ExceptionType.Throw(sprintf('%s 错误发生在第%u个元素',Detail.InnerException,Detail.Index),Detail=Detail);
				else
					ExceptionType.Throw(Detail.InnerException,Detail=Detail);
				end
			end
		end
	end
end