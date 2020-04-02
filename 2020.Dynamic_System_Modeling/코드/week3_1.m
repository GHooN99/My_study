%%plot 
gasprices = readtable("../������/gasprices.xlsx", "Range", "A5:K24");

Year = gasprices.Year;

Au = gasprices.Australia;
Ge = gasprices.Germany;
Me = gasprices.Mexico;

avg = mean(Au(~isnan(Au))); %nan �� �ƴѰ͵��� ��� 
Au(isnan(Au)) = avg;

plot(Year,Au,'r--o')
plot(Year,Ge,'g--o')
plot(Year,Me,'b--o')
