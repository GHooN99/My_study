CarSpecs = readtable("../데이터/CarSpecs.xls"); %모두 가져옴
CarSpecs1 = xlsread("../데이터/CarSpecs.xls"); %숫자만 가져와서 자료 손상 

figure("Name","Power EngineSize")
scatter(CarSpecs.EngineSize,CarSpecs.Power);
xlabel('EngineSize');
ylabel('Power');
title("Power vs EngineSize");

PtW = CarSpecs.Power ./ CarSpecs.Weight;  %PtW 열 추가 

CarSpecs.PtW = PtW

[PtW_Max,idx] = max(CarSpecs.PtW)

%% Cell Array

CarSpecs.Model{1}    %문자열 뽑기  

CarSpecs.Make{idx}

[byPtw,index] = sortrows(CarSpecs,'PtW','descend'); % 원본 인덱스도 반환

