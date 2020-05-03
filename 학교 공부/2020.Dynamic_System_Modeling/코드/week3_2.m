%%plot 
gasprices = readtable("../데이터/gasprices.xlsx", "Range", "A5:K24");

Year = gasprices.Year;

Au = gasprices.Australia;
Ge = gasprices.Germany;
Me = gasprices.Mexico;

avg = mean(Au(~isnan(Au))); %nan 이 아닌것들의 평균 
Au(isnan(Au)) = avg;

plot(Year,Au,'r--o')
plot(Year,Ge,'g--o')
plot(Year,Me,'b--o')
