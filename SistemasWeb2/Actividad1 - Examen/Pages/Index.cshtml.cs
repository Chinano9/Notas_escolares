using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.Collections.Generic;
using System.Linq;

namespace Actividad1.Pages
{
    public class IndexModel : PageModel
    {
        private readonly ILogger<IndexModel> _logger;

        public IndexModel(ILogger<IndexModel> logger)
        {
            _logger = logger;
            InitializeQuestions();
            TotalPoints = Questions.Sum(q => q.Points);
        }

        // Modelos para las preguntas y opciones
        public enum QuestionType
        {
            SingleChoice,
            MultipleChoice
        }

        public class Option
        {
            public string Text { get; set; }
            public bool IsCorrect { get; set; }
            public bool Selected { get; set; } = false;
        }

        public class Question
        {
            public string Text { get; set; }
            public List<Option> Options { get; set; } = new List<Option>();
            public QuestionType Type { get; set; }
            public string Explanation { get; set; }
            public bool IsCorrect =>
                Type == QuestionType.SingleChoice
                    ? Options.Any(o => o.Selected && o.IsCorrect)
                    : Options.All(o => o.Selected == o.IsCorrect);
            public int Points { get; set; } = 1;
        }

        // Variables para el estado del examen
        public List<Question> Questions { get; set; } = new List<Question>();
        public bool ExamCompleted { get; set; } = false;
        public int Score { get; set; } = 0;
        public int TotalPoints { get; set; } = 0;
        public int ScorePercentage { get; set; } = 0;

        // Eliminamos la property binding y procesaremos el form manualmente

        // Calculamos el progreso actual (cuántas preguntas tienen al menos una respuesta)
        public int CurrentProgress => (int)Math.Round((double)Questions.Count(q => q.Options.Any(o => o.Selected)) / Questions.Count * 100);

        private void InitializeQuestions()
        {
            Questions.Add(new Question
            {
                Text = "¿Qué nota se encuentra una tercera mayor por encima de Do?",
                Type = QuestionType.SingleChoice,
                Options = new List<Option>
                        {
                            new Option { Text = "Fa", IsCorrect = false },
                            new Option { Text = "Mi", IsCorrect = true },
                            new Option { Text = "Mi bemol", IsCorrect = false },
                            new Option { Text = "Sol", IsCorrect = false }
                        },
                Explanation = "Una tercera mayor a partir de Do consiste en dos tonos enteros, lo que nos lleva a la nota Mi.",
                Points = 1
            });

            Questions.Add(new Question
            {
                Text = "¿Cuántas corcheas hay en una redonda en un compás de 4/4?",
                Type = QuestionType.SingleChoice,
                Options = new List<Option>
                        {
                            new Option { Text = "2", IsCorrect = false },
                            new Option { Text = "4", IsCorrect = false },
                            new Option { Text = "8", IsCorrect = true },
                            new Option { Text = "16", IsCorrect = false }
                        },
                Explanation = "Una redonda dura 4 tiempos, y una corchea dura medio tiempo. Por lo tanto, 4 / 0.5 = 8.",
                Points = 1
            });

            Questions.Add(new Question
            {
                Text = "¿Qué significa la indicación de tempo 'Andante'?",
                Type = QuestionType.SingleChoice,
                Options = new List<Option>
                        {
                            new Option { Text = "Lento, como un caminante", IsCorrect = false },
                            new Option { Text = "Rápido y animado", IsCorrect = false },
                            new Option { Text = "A un ritmo moderado, como caminando", IsCorrect = true },
                            new Option { Text = "Muy lento y solemne", IsCorrect = false }
                        },
                Explanation = "El término 'Andante' viene del italiano y significa 'caminando', por lo que indica un tempo moderado.",
                Points = 1
            });

            Questions.Add(new Question
            {
                Text = "Una armadura con un sostenido indica la tonalidad de:",
                Type = QuestionType.SingleChoice,
                Options = new List<Option>
                        {
                            new Option { Text = "Re mayor o Si menor", IsCorrect = false },
                            new Option { Text = "Do mayor o La menor", IsCorrect = false },
                            new Option { Text = "Sol mayor o Mi menor", IsCorrect = true },
                            new Option { Text = "Fa mayor o Re menor", IsCorrect = false }
                        },
                Explanation = "La armadura con un sostenido (Fa#) corresponde a la tonalidad de Sol mayor y su relativa menor, Mi menor.",
                Points = 1
            });

            Questions.Add(new Question
            {
                Text = "¿Qué intervalo se forma entre las notas Do y Sol?",
                Type = QuestionType.SingleChoice,
                Options = new List<Option>
                        {
                            new Option { Text = "Tercera mayor", IsCorrect = false },
                            new Option { Text = "Cuarta justa", IsCorrect = false },
                            new Option { Text = "Quinta justa", IsCorrect = true },
                            new Option { Text = "Sexta menor", IsCorrect = false }
                        },
                Explanation = "El intervalo entre Do y Sol abarca cinco notas diatónicas y tiene 3.5 tonos, lo que lo clasifica como una quinta justa.",
                Points = 1
            });

            Questions.Add(new Question
            {
                Text = "¿Qué tipo de acorde se forma con las notas Do, Mi, Sol?",
                Type = QuestionType.SingleChoice,
                Options = new List<Option>
                        {
                            new Option { Text = "Do menor", IsCorrect = false },
                            new Option { Text = "Do disminuido", IsCorrect = false },
                            new Option { Text = "Do mayor", IsCorrect = true },
                            new Option { Text = "Do aumentado", IsCorrect = false }
                        },
                Explanation = "Un acorde mayor se construye con una tercera mayor (Do-Mi) seguida de una tercera menor (Mi-Sol).",
                Points = 1
            });

            Questions.Add(new Question
            {
                Text = "¿Qué son los enarmónicos?",
                Type = QuestionType.SingleChoice,
                Options = new List<Option>
                        {
                            new Option { Text = "Notas que se escriben igual pero suenan diferente", IsCorrect = false },
                            new Option { Text = "Notas que suenan igual pero se escriben de manera diferente", IsCorrect = true },
                            new Option { Text = "Dos notas que forman un intervalo de segunda menor", IsCorrect = false },
                            new Option { Text = "El nombre de las notas que se tocan con la mano izquierda", IsCorrect = false }
                        },
                Explanation = "Las notas enarmónicas, como Do sostenido y Re bemol, tienen la misma altura (suenan igual) pero diferentes nombres.",
                Points = 1
            });

            // Preguntas de opción múltiple (checkbox)
            Questions.Add(new Question
            {
                Text = "En un compás de 3/4, ¿qué figuras musicales pueden durar un tiempo?",
                Type = QuestionType.MultipleChoice,
                Options = new List<Option>
                        {
                            new Option { Text = "Una negra", IsCorrect = true },
                            new Option { Text = "Dos corcheas", IsCorrect = true },
                            new Option { Text = "Cuatro semicorcheas", IsCorrect = true },
                            new Option { Text = "Una blanca", IsCorrect = false }
                        },
                Explanation = "En un compás de 3/4, la negra recibe un tiempo. Dos corcheas o cuatro semicorcheas también suman un tiempo.",
                Points = 2
            });

            Questions.Add(new Question
            {
                Text = "¿Cuáles de los siguientes son elementos de la armonía musical?",
                Type = QuestionType.MultipleChoice,
                Options = new List<Option>
                        {
                            new Option { Text = "Acordes", IsCorrect = true },
                            new Option { Text = "Progresiones de acordes", IsCorrect = true },
                            new Option { Text = "Melodía", IsCorrect = false },
                            new Option { Text = "Escalas", IsCorrect = false }
                        },
                Explanation = "La armonía estudia la formación de acordes y sus progresiones. La melodía y las escalas son conceptos relacionados pero no son directamente elementos de la armonía.",
                Points = 2
            });

            Questions.Add(new Question
            {
                Text = "¿Cuáles de los siguientes son signos de alteración?",
                Type = QuestionType.MultipleChoice,
                Options = new List<Option>
                        {
                            new Option { Text = "Sostenido (#)", IsCorrect = true },
                            new Option { Text = "Bemol (b)", IsCorrect = true },
                            new Option { Text = "Calderón", IsCorrect = false },
                            new Option { Text = "Becuadro", IsCorrect = true }
                        },
                Explanation = "El sostenido, el bemol y el becuadro son signos que modifican la altura de una nota. El calderón es un signo de prolongación de una nota.",
                Points = 2
            });

        }

        public void OnGet()
        {
            // No es necesario hacer nada adicional aquí, ya que inicializamos las preguntas en el constructor
        }

        public IActionResult OnPost()
        {
            _logger.LogInformation("Procesando envío del formulario");
            _logger.LogInformation($"Hay {Questions.Count} preguntas en total");

            // Reset all selections first
            foreach (var question in Questions)
            {
                foreach (var option in question.Options)
                {
                    option.Selected = false;
                }
            }

            try
            {
                // Procesar directamente los datos del formulario
                var form = Request.Form;

                // Log de los datos recibidos para debugging
                foreach (var key in form.Keys)
                {
                    _logger.LogInformation($"Form Key: {key}, Value: {string.Join(", ", form[key].ToArray())}");
                }

                // Procesar checkboxes (multiple choice)
                for (int i = 0; i < Questions.Count; i++)
                {
                    var question = Questions[i];

                    if (question.Type == QuestionType.MultipleChoice)
                    {
                        // Buscar todos los checkboxes marcados para esta pregunta
                        for (int j = 0; j < question.Options.Count; j++)
                        {
                            string checkboxName = $"q{i}_opt{j}";
                            if (form.ContainsKey(checkboxName))
                            {
                                string formValue = form[checkboxName].ToString();
                                _logger.LogInformation($"Checkbox {checkboxName} encontrado con valor: {formValue}");
                                if (formValue.Contains("true"))
                                {
                                    question.Options[j].Selected = true;
                                    _logger.LogInformation($"Checkbox {checkboxName} marcado - opción: {question.Options[j].Text}");
                                }
                            }
                        }
                    }
                    else if (question.Type == QuestionType.SingleChoice)
                    {
                        // Buscar el radio button seleccionado para esta pregunta
                        string radioName = $"q{i}";
                        if (form.ContainsKey(radioName))
                        {
                            string radioValue = form[radioName].ToString();
                            _logger.LogInformation($"Radio {radioName} encontrado con valor: {radioValue}");
                            if (int.TryParse(radioValue, out int selectedIndex))
                            {
                                if (selectedIndex >= 0 && selectedIndex < question.Options.Count)
                                {
                                    question.Options[selectedIndex].Selected = true;
                                    _logger.LogInformation($"Radio {radioName} seleccionado: {selectedIndex} (opción: {question.Options[selectedIndex].Text})");
                                }
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                _logger.LogError($"Error al procesar el formulario: {ex.Message}");
            }

            // Calcular la puntuación
            Score = 0;
            foreach (var question in Questions)
            {
                _logger.LogInformation($"Pregunta: {question.Text}");
                _logger.LogInformation($"  - Es correcta: {question.IsCorrect}");
                _logger.LogInformation($"  - Opciones seleccionadas: {string.Join(", ", question.Options.Where(o => o.Selected).Select(o => o.Text))}");

                if (question.IsCorrect)
                {
                    Score += question.Points;
                    _logger.LogInformation($"  - Puntos sumados: {question.Points}");
                }
            }

            ScorePercentage = (int)Math.Round((double)Score / TotalPoints * 100);
            ExamCompleted = true;

            _logger.LogInformation($"Puntuación final: {Score} de {TotalPoints} ({ScorePercentage}%)");
            _logger.LogInformation("Examen completado: " + ExamCompleted);

            return Page();
        }

        public IActionResult OnPostReset()
        {
            // Reiniciar el estado del examen
            foreach (var question in Questions)
            {
                foreach (var option in question.Options)
                {
                    option.Selected = false;
                }
            }


            // Log the current state before reset
            _logger.LogInformation($"Estado actual antes de reset - Puntuación: {Score}, Completado: {ExamCompleted}");

            Score = 0;
            ScorePercentage = 0;
            ExamCompleted = false;

            return Page();
        }

        public string GetScoreClass()
        {
            if (ScorePercentage >= 80)
                return "bg-success";
            else if (ScorePercentage >= 60)
                return "bg-info";
            else
                return "bg-warning";
        }
    }
}
