clear; clc;
close all;

[x, fs] = audioread('test.wav');
% x will be a matrix of size [n_samples * n_channels]
% n_samples = audio_length * fs, the unit of audio_length is seconds
% fs will be the sampling frequency of the audio (Hz)
n_samples = size(x, 1);
n_channels = size(x, 2);
time = zeros(n_samples, 1);
for sample = 1:n_samples
    time(sample) = sample/fs;
end
figure;
for channel = 1:n_channels
    p(channel) = subplot(n_channels, 1, channel);
    plot(time, x(:,channel));
    ylim(p(channel),[-1,1]);
    ylabel(strcat('track-', int2str(channel)));
end
xlabel('time (seconds)');
title(p(1), 'Waveform for the input audio');
