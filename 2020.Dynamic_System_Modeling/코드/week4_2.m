CarSpecs = readtable("../������/CarSpecs.xls"); %��� ������
CarSpecs1 = xlsread("../������/CarSpecs.xls"); %���ڸ� �����ͼ� �ڷ� �ջ� 

figure("Name","Power EngineSize")
scatter(CarSpecs.EngineSize,CarSpecs.Power);
xlabel('EngineSize');
ylabel('Power');
title("Power vs EngineSize");

PtW = CarSpecs.Power ./ CarSpecs.Weight;  %PtW �� �߰� 

CarSpecs.PtW = PtW

[PtW_Max,idx] = max(CarSpecs.PtW)

%% Cell Array

CarSpecs.Model{1}    %���ڿ� �̱�  

CarSpecs.Make{idx}

[byPtw,index] = sortrows(CarSpecs,'PtW','descend'); % ���� �ε����� ��ȯ

