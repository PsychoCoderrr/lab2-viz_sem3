#pragma once
#include "HeadSorter.h"
#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <ranges>

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, unsigned int red, unsigned int blue)
{
    int index = 0;
    for(int i:v)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, index, 99, index, i);
        index += 1;
    }
}


template<typename T, typename iterator>
struct BubbleSort : public HeadSorter<T, iterator>
{
    void sort(iterator begin, iterator end, bool (*comparator)(const T&, const T&)) override
    {
        for (auto i = begin; i != end; ++i) {
                for (auto j = begin; j != end - (i - begin) - 1; ++j) {
                    if (!comparator(*j, *(j + 1))) {
                        std::swap(*j, *(j + 1)); // Обмен элементов
                    }
                }
            }
    }
    
    void sort_viz()
    {
        std::random_device rd;
        std::uniform_int_distribution d(1, 99);
        std::vector<int> v;
        for (int i = 0; i < 100; i++)
        {
            v.push_back(d(rd));
        }
    
        SDL_Window* window = SDL_CreateWindow("Sorting Visualization",
                                                  SDL_WINDOWPOS_CENTERED,
                                                  SDL_WINDOWPOS_CENTERED,
                                                  1000, 1000,
                                                  SDL_WINDOW_SHOWN);

        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        //SDL_CreateWindowAndRenderer(100*10, 100*10, 0, &window, &renderer);
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        SDL_RenderSetScale(renderer, 10, 10);
    
        for (unsigned int i = 0; i < v.size(); i++)
        {
            for (unsigned int j = i; j < v.size(); j++)
            {
                if (v[j] > v[i])
                {
                    std::swap(v[j], v[i]);
                }
                SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                SDL_RenderClear(renderer);
                draw_state(v, renderer, i, j);
                SDL_RenderPresent(renderer);
                SDL_Delay(10);
            }
        }
    }
    
};

