function V = Version
V.Me='v19.0.0';
V.MATLAB='R2023b';
persistent NewVersion
try
	if isempty(NewVersion)
		NewVersion=TextAnalytics.CheckUpdateFromGitHub('https://github.com/Silver-Fang/MATLAB-Extension/releases','埃博拉酱的MATLAB扩展',V.Me);
	end
catch ME
	if ME.identifier~="MATLAB:undefinedVarOrClass"
		ME.rethrow;
	end
end