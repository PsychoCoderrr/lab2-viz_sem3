#pragma once
#include "HeadSorter.h"
//#include "Book.h"
#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <ranges>

template<typename T, typename iterator>
struct QuickSort: public HeadSorter<T, iterator>
{
    void sort(iterator begin, iterator end, bool (*comparator)(const T &, const T &)) override
        {
            if (begin == end || begin + 1 == end)
                return;

            auto pivot = partition(begin, end, comparator);

            sort(begin, pivot, comparator);
            sort(pivot + 1, end, comparator);
        }

      private:
        iterator partition(iterator begin, iterator end, bool (*comparator)(const T &, const T &))
        {
            auto pivot = end - 1;
            auto i = begin - 1;

            for (auto j = begin; j != pivot; ++j)
            {
                if (comparator(*j, *pivot))
                {
                    ++i;
                    std::swap(*i, *j);
                }
            }

            ++i;
            std::swap(*i, *pivot);

            return i;
        }
    
    
    
    
    

public:
    void sort_viz() {
        std::random_device rd;
        std::uniform_int_distribution<int> dist(1, 99);
        std::vector<int> arr(100);
        for (int& val : arr) {
            val = dist(rd);
        }

        SDL_Window* window = SDL_CreateWindow(
            "Quick Sort Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_SHOWN);
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        SDL_RenderSetScale(renderer, 10, 10);

        quick_sort_visualized(arr.begin(), arr.end(), [](const int& a, const int& b) { return a < b; }, renderer, arr);

        SDL_Delay(2000); // Задержка перед закрытием окна
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        }
    void quick_sort_visualized(
        iterator begin, iterator end, bool (*comparator)(const T&, const T&), SDL_Renderer* renderer, std::vector<T>& arr) {
        if (begin == end || begin + 1 == end)
            return;

        auto pivot = partition(begin, end, comparator);

        // Визуализация массива
        draw_array(renderer, arr, begin - arr.begin(), end - arr.begin(), pivot - arr.begin());

        quick_sort_visualized(begin, pivot, comparator, renderer, arr);
        quick_sort_visualized(pivot + 1, end, comparator, renderer, arr);
        }

        void draw_array(SDL_Renderer* renderer, const std::vector<T>& arr, size_t left, size_t right, size_t pivot) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Чёрный фон
            SDL_RenderClear(renderer);

            for (size_t i = 0; i < arr.size(); ++i) {
                if (i == pivot) {
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Красный - опорный элемент
                } else if (i >= left && i < right) {
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Зелёный - текущий подмассив
                } else {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Белый - остальные элементы
                }

                SDL_RenderDrawLine(renderer, i, 99, i, 99 - arr[i]);
            }

            SDL_RenderPresent(renderer);
            SDL_Delay(1000); // Задержка для наглядности
        }
};
