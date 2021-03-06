## ---- include = FALSE---------------------------------------------------------
knitr::opts_chunk$set(
  collapse = TRUE,
  comment = "#>"
)

## ---- echo = FALSE, fig.width = 6, fig.height= 6, fig.align = "center", warning = FALSE, message = FALSE----
library(Rrelperm)
library(ggplot2)
library(magrittr)
library(tidyr)

rel_perm_ow <- kr2p_ow(SWCON = 0.13, SWCRIT = 0.20, SOIRW = 0.15, SORW = 0.22, 
                       KRWIRO = 0.45, KROCW = 1, NW = 1.5, NOW = 1.5, NP = 101)

rel_perm_ow_df <- as.data.frame(rel_perm_ow)
colnames(rel_perm_ow_df) <- c("Sw", "So", "Krw", "Krow")

p1 <- rel_perm_ow_df %>% 
  tidyr::pivot_longer(cols = c(Krw, Krow), values_to = "value",  names_to = "Kr") %>%
  ggplot(aes(x = Sw, y = value, col = Kr)) +
  geom_point() +
  labs(title = "water-oil relative permeability", x = "Sw", y = "Kr") +
  geom_segment(x = 0.0, y = 0.05, xend = 0.13, yend = 0.05, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "both", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.07, y=0.075, label="SWCON", size = 3, color="black") +
  geom_segment(x = 0.0, y = 0.1, xend = 0.2, yend = 0.1, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "both", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.105, y=0.125, label="SWCRIT", size = 3, color="black") +
  geom_segment(x = 0.85, y = 0.05, xend = 1.0, yend = 0.05, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "both", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.92, y=0.075, label="SOIRW", size = 3, color="black") +
  geom_segment(x = 0.78, y = 0.1, xend = 1.0, yend = 0.1, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "both", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.885, y=0.125, label="SORW", size = 3, color="black") +
  geom_segment(x = 0.65, y = 0.45, xend = 0.80, yend = 0.45, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "last", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.725, y=0.475, label = "KRWIRO", size = 3, color="black") +
  geom_segment(x = 0.18, y = 1.0, xend = 0.33, yend = 1.0, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "first", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.275, y = 0.975, label = "KROCW", size = 3, color="black") +
  theme_bw()

p1

## ---- echo = FALSE, fig.width = 6, fig.height= 6, fig.align = "center", warning = FALSE, message = FALSE----
library(Rrelperm)
library(ggplot2)
library(magrittr)

rel_perm_gl <- kr2p_gl(SWCON = 0.13, SOIRG = 0.10, SORG = 0.15, SGCON = 0.05, 
                       SGCRIT = 0.1, KRGCL = 0.45, KROGCG = 1.0, NG = 1.25, NOG = 1.25, 
                       NP = 101)

rel_perm_gl_df <- as.data.frame(rel_perm_gl)
colnames(rel_perm_gl_df) <- c("Sg", "Sl", "Krg", "Krog")

p2 <- rel_perm_gl_df %>% tidyr::pivot_longer(cols = c(Krg, Krog), values_to = "value", 
                                             names_to = "Kr") %>%
  ggplot(aes(x = Sg, y = value, col = Kr)) +
  geom_point() +
  labs(title = "gas-liquid relative permeability", x = "Sg", y = "Kr") +
  geom_segment(x = 0.0, y = 0.05, xend = 0.05, yend = 0.05, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "both", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.03, y=0.075, label="SGCON", size = 3, color="black") +
  geom_segment(x = 0.0, y = 0.1, xend = 0.1, yend = 0.1, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "both", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.05, y=0.125, label="SGCRIT", size = 3, color="black") +
  geom_segment(x = 0.77, y = 0.05, xend = 1.0, yend = 0.05, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "both", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.92, y=0.075, label="SLCON", size = 3, color="black") +
  geom_segment(x = 0.72, y = 0.1, xend = 1.0, yend = 0.1, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "both", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.885, y=0.125, label="SLRG", size = 3, color="black") +
  annotate(geom="text", x=0.8, y=0.950, label="SLCON = SWCON + SOIRG", size = 3, 
           color="black") +
  annotate(geom="text", x=0.8, y=0.9, label="SLRG = SWCON + SORG", size = 3, 
           color="black") +
  geom_segment(x = 0.575, y = 0.45, xend = 0.7, yend = 0.45, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "last", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.635, y=0.475, label = "KRGCL", size = 3, color="black") +
  geom_segment(x = 0.1, y = 1.0, xend = 0.25, yend = 1.0, lineend = "round", 
               linejoin = "round", size = 1, 
               arrow = arrow(end = "first", length = unit(0.075, "inches")), 
               colour = "black") + 
  annotate(geom="text", x=0.185, y = 0.975, label = "KROGCG", size = 3, color="black") +
  theme_bw()

p2

## ---- eval = FALSE, warning = FALSE-------------------------------------------
#  install.packages("Rrelperm")

## ---- fig.width = 6, fig.height= 4, fig.align = "center", warning = TRUE------
library(Rrelperm)
library(ggplot2)
library(magrittr)
library(tidyr)

rel_perm_ow <- kr2p_ow(SWCON = 0.13, SWCRIT = 0.13, SOIRW = 0.20, SORW = 0.2, 
                       KRWIRO = 0.45, KROCW = 1, NW = 4.25, NOW = 2.5, NP = 101)

rel_perm_ow_df <- as.data.frame(rel_perm_ow)
colnames(rel_perm_ow_df) <- c("Sw", "So", "Krw", "Krow")

head(rel_perm_ow_df, 10)

p1 <- rel_perm_ow_df %>% tidyr::pivot_longer(cols = c(Krw, Krow), values_to = "value", 
                                             names_to = "Kr") %>%
  ggplot(aes(x = Sw, y = value, col = Kr)) +
  geom_point() +
  labs(title = "water-oil relative permeability", x = "Sw", y = "Kr") +
  theme_bw()

p1

## ---- fig.width = 6, fig.height= 4, fig.align = "center", warning = TRUE------
library(Rrelperm)
library(ggplot2)
library(magrittr)

rel_perm_gl <- kr2p_gl(SWCON = 0.13, SOIRG = 0.12, SORG = 0.12, SGCON = 0.05, 
                       SGCRIT = 0.05, KRGCL = 0.35, KROGCG = 1, NG = 4.25, NOG = 2.5, 
                       NP = 101)

rel_perm_gl_df <- as.data.frame(rel_perm_gl)
colnames(rel_perm_gl_df) <- c("Sg", "Sl", "Krg", "Krog")

head(rel_perm_gl_df)

p2 <- rel_perm_gl_df %>% tidyr::pivot_longer(cols = c(Krg, Krog), values_to = "value", 
                                             names_to = "Kr") %>%
  ggplot(aes(x = Sg, y = value, col = Kr)) +
  geom_point() +
  labs(title = "gas-liquid relative permeability", x = "Sg", y = "Kr") +
  theme_bw()

p2

## ---- fig.width = 6, fig.height= 6, fig.align = "center", warning = TRUE------
library(Rrelperm)
library(ggplot2)
library(ggtern)
library(magrittr)

rel_perm_owg_st_i_swsg <- kr3p_StoneI_SwSg(SWCON = 0.13, SWCRIT = 0.13, SOIRW = 0.20, 
                                      SORW = 0.2, SOIRG = 0.1, SORG = 0.1, SGCON = 0, 
                                      SGCRIT = 0, KRWIRO = 0.45, KROCW = 1, KRGCL = 0.35, 
                                      NW = 4.25, NOW = 2.5, NG = 3, NOG = 2, 
                                      NP = 501)

rel_perm_owg_st_i_swsg <- as.data.frame(rel_perm_owg_st_i_swsg)
colnames(rel_perm_owg_st_i_swsg) <- c("Sw", "Sg", "So", "Kro")

head(rel_perm_owg_st_i_swsg, 10)

rel_perm_owg_st_i_swsg$Kro_range <- cut(rel_perm_owg_st_i_swsg$Kro, breaks = seq(0,1, by = 0.1),
                                   right = TRUE, include.lowest = FALSE)

rel_perm_owg_st_i_swsg_oil <- rel_perm_owg_st_i_swsg[rel_perm_owg_st_i_swsg$Kro > 0, ]

rel_perm_owg_st_i_swsg_oil <- droplevels(rel_perm_owg_st_i_swsg_oil)

p3 <- ggtern(data = rel_perm_owg_st_i_swsg_oil, aes(x = Sw, y = Sg, z = So, value = Kro)) +
  geom_point(aes(value = Kro, fill = Kro_range, color = Kro_range), size = 1, shape = 22) +
  scale_T_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  scale_L_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  scale_R_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  ggtitle("Three-phase Oil Relative Permeability - STONE I, SWSG") +
  theme_classic()

p3


## ---- fig.width = 6, fig.height= 6, fig.align = "center", warning = TRUE------
library(Rrelperm)
library(ggplot2)
library(ggtern)
library(magrittr)

rel_perm_owg_st_i_so <- kr3p_StoneI_So(SWCON = 0.13, SWCRIT = 0.13, SOIRW = 0.20, 
                                      SORW = 0.2, SOIRG = 0.1, SORG = 0.1, SGCON = 0, 
                                      SGCRIT = 0, KRWIRO = 0.45, KROCW = 1, KRGCL = 0.35, 
                                      NW = 4.25, NOW = 2.5, NG = 3, NOG = 2, 
                                      NP = 501)

rel_perm_owg_st_i_so <- as.data.frame(rel_perm_owg_st_i_so)
colnames(rel_perm_owg_st_i_so) <- c("Sw", "Sg", "So", "Kro")

head(rel_perm_owg_st_i_so, 10)

rel_perm_owg_st_i_so$Kro_range <- cut(rel_perm_owg_st_i_so$Kro, breaks = seq(0,1, by = 0.1),
                                   right = TRUE, include.lowest = FALSE)

rel_perm_owg_st_i_so_oil <- rel_perm_owg_st_i_so[rel_perm_owg_st_i_so$Kro > 0, ]

rel_perm_owg_st_i_so_oil <- droplevels(rel_perm_owg_st_i_so_oil)

p4 <- ggtern(data = rel_perm_owg_st_i_so_oil, aes(x = Sw, y = Sg, z = So, value = Kro)) +
  geom_point(aes(value = Kro, fill = Kro_range, color = Kro_range), size = 1, shape = 22) +
  scale_T_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  scale_L_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  scale_R_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  ggtitle("Three-phase Oil Relative Permeability - STONE I, SO") +
  theme_classic()

p4


## ---- fig.width = 6, fig.height= 6, fig.align = "center", warning = TRUE------
library(Rrelperm)
library(ggplot2)
library(ggtern)
library(magrittr)

rel_perm_owg_st_ii_swsg <- kr3p_StoneII_SwSg(SWCON = 0.13, SWCRIT = 0.13, SOIRW = 0.20, 
                                      SORW = 0.2, SOIRG = 0.1, SORG = 0.1, SGCON = 0, 
                                      SGCRIT = 0, KRWIRO = 0.45, KROCW = 1, KRGCL = 0.35, 
                                      NW = 4.25, NOW = 2.5, NG = 3, NOG = 2, 
                                      NP = 501)

rel_perm_owg_st_ii_swsg <- as.data.frame(rel_perm_owg_st_ii_swsg)
colnames(rel_perm_owg_st_ii_swsg) <- c("Sw", "Sg", "So", "Kro")

head(rel_perm_owg_st_ii_swsg, 10)

rel_perm_owg_st_ii_swsg$Kro_range <- cut(rel_perm_owg_st_ii_swsg$Kro, breaks = seq(0,1, by = 0.1),
                                   right = TRUE, include.lowest = FALSE)

rel_perm_owg_st_ii_swsg_oil <- rel_perm_owg_st_ii_swsg[rel_perm_owg_st_ii_swsg$Kro > 0, ]

rel_perm_owg_st_ii_swsg_oil <- droplevels(rel_perm_owg_st_ii_swsg_oil)

p5 <- ggtern(data = rel_perm_owg_st_ii_swsg_oil, aes(x = Sw, y = Sg, z = So, value = Kro)) +
  geom_point(aes(value = Kro, fill = Kro_range, color = Kro_range), size = 1, shape = 22) +
  scale_T_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  scale_L_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  scale_R_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  ggtitle("Three-phase Oil Relative Permeability - STONE II, SWSG") +
  theme_classic()

p5


## ---- fig.width = 6, fig.height= 6, fig.align = "center", warning = TRUE------
library(Rrelperm)
library(ggplot2)
library(ggtern)
library(magrittr)

rel_perm_owg_st_ii_so <- kr3p_StoneII_So(SWCON = 0.13, SWCRIT = 0.13, SOIRW = 0.20, 
                                      SORW = 0.2, SOIRG = 0.1, SORG = 0.1, SGCON = 0, 
                                      SGCRIT = 0, KRWIRO = 0.45, KROCW = 1, KRGCL = 0.35, 
                                      NW = 4.25, NOW = 2.5, NG = 3, NOG = 2, 
                                      NP = 501)

rel_perm_owg_st_ii_so <- as.data.frame(rel_perm_owg_st_ii_so)
colnames(rel_perm_owg_st_ii_so) <- c("Sw", "Sg", "So", "Kro")

head(rel_perm_owg_st_ii_so, 10)

rel_perm_owg_st_ii_so$Kro_range <- cut(rel_perm_owg_st_ii_so$Kro, breaks = seq(0,1, by = 0.1),
                                   right = TRUE, include.lowest = FALSE)

rel_perm_owg_st_ii_so_oil <- rel_perm_owg_st_ii_so[rel_perm_owg_st_ii_so$Kro > 0, ]

rel_perm_owg_st_ii_so_oil <- droplevels(rel_perm_owg_st_ii_so_oil)

p6 <- ggtern(data = rel_perm_owg_st_ii_so_oil, aes(x = Sw, y = Sg, z = So, value = Kro)) +
  geom_point(aes(value = Kro, fill = Kro_range, color = Kro_range), size = 1, shape = 22) +
  scale_T_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  scale_L_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  scale_R_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  ggtitle("Three-phase Oil Relative Permeability - STONE II, SO") +
  theme_classic()

p6


## ---- fig.width = 6, fig.height= 6, fig.align = "center", warning = TRUE------
library(Rrelperm)
library(ggplot2)
library(ggtern)
library(magrittr)

rel_perm_owg_bk <- kr3p_Baker(SWCON = 0.13, SWCRIT = 0.13, SOIRW = 0.20, 
                                      SORW = 0.2, SOIRG = 0.1, SORG = 0.1, SGCON = 0, 
                                      SGCRIT = 0, KRWIRO = 0.45, KROCW = 1, KRGCL = 0.35, 
                                      NW = 4.25, NOW = 2.5, NG = 3, NOG = 2, 
                                      NP = 501)

rel_perm_owg_bk <- as.data.frame(rel_perm_owg_bk)
colnames(rel_perm_owg_bk) <- c("Sw", "Sg", "So", "Kro")

head(rel_perm_owg_bk, 10)

rel_perm_owg_bk$Kro_range <- cut(rel_perm_owg_bk$Kro, breaks = seq(0,1, by = 0.1),
                                   right = TRUE, include.lowest = FALSE)

rel_perm_owg_bk_oil <- rel_perm_owg_bk[rel_perm_owg_bk$Kro > 0, ]

rel_perm_owg_bk_oil <- droplevels(rel_perm_owg_bk_oil)

p7 <- ggtern(data = rel_perm_owg_bk_oil, aes(x = Sw, y = Sg, z = So)) +
  geom_point(aes(value = Kro, fill = Kro_range, color = Kro_range), size = 1, shape = 22) +
  scale_T_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  scale_L_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  scale_R_continuous(limits = c(0.0,1.0), breaks = seq(0,1,by = 0.05)) +
  ggtitle("Three-phase Oil Relative Permeability - Baker's Linear") +
  theme_classic()

p7


