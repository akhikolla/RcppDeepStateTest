library(ggplot2)
df <- data.frame(x = x.fuzz)
ggplot(df, aes(x)) + geom_histogram()

p <- ggplot(df, aes(x)) + geom_point()
p + labs(colour = "Cylinders")

ggplot(mtcars, aes(x=wt, y=mpg)) + geom_point()
# Change the point size, and shape
ggplot(df, aes(x, y="fuzzer")) +
  geom_point()


plt.scatter(, "fuzzer", color = "black")

ggplot(df, aes(x = x)) + 
  geom_point() + ggtitle("meter value for dataID=35") +
  theme(axis.text.x = element_text(angle = 90,))


ggplot(data = dat,
       mapping = aes(x = reorder(CNT, science), y = science, fill = Region)) +
  geom_boxplot() +
  labs(x=NULL, y="Science Scores") +
  coord_flip() +
  geom_hline(yintercept = 493, linetype="dashed", color = "red", size = 1) +
  theme_bw()



ggplot(data = x,
       mapping = aes(x = var, fill = Region)) +
  geom_histogram(alpha = 0.5, bins = 50) +
  labs(x = "Science Scores", y = "Count",
       title = "Science Scores by Gender and Region") +
  facet_grid(. ~ sex) +
  theme_bw()


##Working code for per minute generation
ggplot(data = nlists,
       mapping = aes(x = fuzzer, y = InputsperMinute, size = InputsperMinute, fill = fuzzer)) +
  geom_point(shape = 21) +
  coord_flip() +
  theme_bw() +
  labs(x = NULL, y = "InputsperMinute", fill = "fuzzer",
       size = "InputsperMinute")


ggplot(data = science_summary,
       mapping = aes(x = CNT, y = Science, size = Freq, fill = sex)) +
  geom_point(shape = 21) +
  coord_flip() +
  theme_bw() +
  labs(x = NULL, y = "Science Scores", fill = "fuzzer",
       size = "Frequency")